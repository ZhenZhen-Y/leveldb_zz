#ifndef STORAGE_LEVELDB_UTIL_RANDOM_H_
#define STORAGE_LEVELDB_UTIL_RANDOM_H_

#include <stdint.h>

namespace leveldb {
    class Random {
    private:
        uint32_t seed_;
        
    public:
        explicit Random(uint32_t s) : seed_(s & 0x7fffffffu) {
            // Avoid bad seeds
            if (seed_ == 0 || seed_ == 2147483647L) {
                seed_ = 1;
            }
        }
        uint32_t Next() {
            static const uint32_t M = 2147483647L; //2^31-1
            static const uint64_t A = 16807;
            /*
               seed_ = (seed_ * A) % M, seed_ must not be zero or M,
               for all orther values, seed_ will end up cycling through
               every number in [1, M-1]
             */
            uint64_t product = seed_ * A;
            seed_ = static_cast<uint32_t>((product >> 31) + (product & M));
            if(seed_ > M) {
                seed_ -= M;
            }
            return seed_;
        }
        // Return a uniformly distributed value in the range [0..n-1]
        // Requires: n>0
        uint32_t Uinform(int n) { return Next() % n; }
        bool OneIn(int n) { return (Next() % n) == 0; }
        uint32_t Skewed(int max_log) { return Uinform(1 << Uinform(max_log + 1)); }
    };
}

#endif

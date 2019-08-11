#ifndef STORAGE_LEVELDB_UTIL_ARENA_H_
#define STORAGE_LEVELDB_UTIL_ARENA_H_

#include <atomic>
#include <cassert>
#include <cstddef>
#include <cstdint>
#include <vector>

namespace leveldb {
    class Arena {
    public:
        Arena();
        Arena(const Arena&) = delete;
        Arena& operator=(const Arena&) = delete;
        ~Arena();
        
        // Return a pointer to a newly allocated memory block of bytes
        char* Allocate(size_t bytes);
        
        // 使用malloc保证内存分配对齐
        char* AllocateAligned(size_t bytes);
        
        // Return an estimate of total memory usage of data allocated by the arena
        size_t MemoryUsage() const {
            return memory_usage_.load(std::memory_order_relaxed);
        }
    private:
        char* AllocateFallback(size_t bytes);
        char* AllocateNewBlock(size_t block_bytes);
        
        // Allocation state
        char* alloc_ptr_;
        size_t alloc_bytes_remaining_;
        
        // array of new[] allocated memory blocks
        std::vector<char*> blocks_;
        
        // Total memory usage of arena
        std::atomic<size_t> memory_usage_;
    };
    
    inline char* Arena::Allocate(size_t bytes) {
        assert(bytes > 0);
        if (bytes <= alloc_bytes_remaining_) {
            char* result = alloc_ptr_;
            alloc_ptr_ +=bytes;
            alloc_bytes_remaining_ -= bytes;
            return result;
        }
        return AllocateFallback(bytes);
    }
    
}

#endif

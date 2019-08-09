#include <iostream>
#include "leveldb/slice.h"

int main(){
    leveldb::Slice str1 = "hello slice";
    leveldb::Slice str2 ="hello";
    int i=str1.compare(str2);
    std::cout << i;
    return 0;
}

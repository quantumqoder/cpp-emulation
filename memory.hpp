#ifndef MEMORY_HPP
#define MEMORY_HPP

#include "types.hpp"

class Memory
{
    static constexpr s32 MAX_MEM = 1024 * 64;
    byte mem[MAX_MEM];

public:
    Memory();
    Memory(const Memory &other);
    byte operator[](s32 addr) const { return mem[addr]; }
    byte &operator[](s32 addr) { return mem[addr]; }
    void dump();
};

#endif

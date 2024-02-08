#ifndef CPU_HPP
#define CPU_HPP

#include "types.hpp"
#include "memory.hpp"

class CPU
{
    word pc;
    word sp;

    byte a, x, y;

    byte c : 1;
    byte z : 1;
    byte i : 1;
    byte d : 1;
    byte b : 1;
    byte v : 1;
    byte n : 1;

    Memory mem;

public:
    static constexpr byte INS_LDA_IM = 0xa9, INS_LDA_ZP = 0xa5;
    CPU(Memory &mem_ref);
    void execute(s32 cycles);
    byte fetch(s32 &cycles);
    byte read(s32 &cycles, word addr);
};

#endif // CPU_HPP
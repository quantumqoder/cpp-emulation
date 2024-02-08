#include "cpu.hpp"

CPU::CPU(Memory &mem_ref) : mem(mem_ref)
{
    pc = 0xfffc;
    sp = 0x0100;
    a = x = y = 0;
    c = z = i = d = b = v = n = 0;
}

void CPU::execute(s32 cycles)
{
    while (cycles > 0)
    {
        printf("\nCycles: %d\n", cycles);
        printf("PC: %04x\n", pc);
        // printf("SP: %04x\n", sp);
        printf("Memory:-\n");
        mem.dump();
        byte ins = fetch(cycles);
        byte imm = fetch(cycles);
        switch (ins)
        {
        case INS_LDA_IM:
        {
            a = imm;
        }
        break;
        case INS_LDA_ZP:
        {
            a = read(cycles, imm);
        }
        default:
            printf("Unidentified instruction: %02x\n", ins);
            break;
        }
        z = a == 0;
        n = (a & 0b10000000) > 0;
        printf("A: %02x\n", a);
        printf("Z: %02x\n", x);
        printf("N: %02x\n", y);
    }
}

byte CPU::fetch(s32 &cycles)
{
    return read(cycles, pc++);
}

byte CPU::read(s32 &cycles, word addr)
{
    printf("{Reading: %02x, ", addr);
    byte ins = mem[addr];
    printf("INS: %02x}\n", ins);
    cycles--;
    return ins;
}
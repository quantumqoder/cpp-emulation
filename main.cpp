#include <stdio.h>

#include "cpu.cpp"
#include "memory.cpp"

// using namespace std;

int main()
{
    Memory mem;
    mem[0xfffc] = CPU::INS_LDA_ZP;
    mem[0xfffd] = 0x42;
    mem[0x0042] = 0x84;
    CPU cpu(mem);
    cpu.execute(3);
}
#include "memory.hpp"

Memory::Memory()
{
    for (int i = 0; i < MAX_MEM; i++)
    {
        mem[i] = 0;
    }
}

Memory::Memory(const Memory &other)
{
    for (int i = 0; i < MAX_MEM; i++)
    {
        mem[i] = other[i];
    }
}

void Memory::dump()
{
    for (int i = 0; i < MAX_MEM; i++)
    {
        if (mem[i] != 0x00)
        {
            printf("%02x %02x\n", i, mem[i]);
        }
    }
}
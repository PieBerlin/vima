#ifndef ASSEMBLY_H
#define ASSEMBLY_H

#include "vima.h"
void push(Machine *machine,int value);
uint64_t pop(Machine *machine);
void mov(Machine *machine, int reg, uint64_t value);

#endif // !ASSEMBLY_H

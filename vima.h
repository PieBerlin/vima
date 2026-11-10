#ifndef VIMA_H
#define VIMA_H

#include <stdio.h>
#include  <stdlib.h>
#include <string.h>
#include <assert.h>

#include "instruction.h"

#define MAX_STACK_SIZE 1024
#define MAX_INSTRUCTION_SIZE 1024


typedef struct CPU{
    // Cache L1,L2,L3;
    // Registers Reg;

}CPU;

typedef struct {
    int stack[MAX_STACK_SIZE];
    int stack_size;
    uint64_t program_size;/* This tells us how many instuctions we have */
    Instruction *instructions;
}Machine;



Machine *init_machine();


#endif // VIMA_H

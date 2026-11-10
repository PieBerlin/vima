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



#define DEF_INST_PUSH(x) {.type = INST_PUSH, .value = x}
#define DEF_INST_POP {.type = INST_POP }
#define DEF_INST_ADD {.type = INST_ADD }
#define DEF_INST_SUB {.type = INST_SUB }
#define DEF_INST_MUL {.type = INST_MUL }
#define DEF_INST_DIV {.type = INST_DIV }
#define DEF_INST_PRINT {.type = INST_PRINT } 

Machine *init_machine();


#endif // VIMA_H

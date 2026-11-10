#ifndef VIMA_H
#define VIMA_H

#include <stdio.h>
#include  <stdlib.h>
#include <string.h>
#include <assert.h>

#include "instruction.h"

#define MAX_STACK_SIZE 1024
#define MAX_INSTRUCTION_SIZE 1024


typedef struct {

    uint64_t regs[16];
    uint64_t stack[MAX_STACK_SIZE];
    uint64_t sp;// stack pointer
    uint64_t program_size;/* This tells us how many instuctions we have */
    Instruction *instructions;
    /*
     * uint64_t pc; // program counter
     * uint64_t fp; frame pointer
     * uint64_t flags 
     * uint64_t heap_ptr 
     * int running;
     * int haltcode ;
     *
     * */
}Machine;



Machine *init_machine();


#endif // VIMA_H

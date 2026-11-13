/* assembly.c Interprets assembly instruction */
#include "assembly.h"
#include "vima.h"


void push(Machine *machine,int value){
    if (machine->sp >= MAX_STACK_SIZE){
        fprintf(stderr, "ERROR: Stack is Full\n");
        exit(1);
    }
    machine->stack[machine->sp] = value;
    machine->sp++;
}

int pop(Machine *machine){
    if (machine->sp <= 0){
        fprintf(stderr, "ERROR: Stack is Empty\n");
        exit(1);
    }
    machine->sp--;
    return machine->stack[machine->sp];
}

void mov(Machine *machine,int reg,uint64_t value){
    machine->regs[reg] = value;
}

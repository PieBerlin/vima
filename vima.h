#ifndef VIMA_H
#define VIMA_H

#include <stdio.h>
#include  <stdlib.h>
#include <string.h>
#include <assert.h>

#define MAX_STACK_SIZE 1024

typedef enum {
    INST_PUSH,
    INST_POP,
    INST_ADD,
    INST_SUB,
    INST_MUL,
    INST_DIV,
    INST_PRINT,

}Inst_Set;
typedef struct Inst{
    Inst_Set type;
    int value;

}Inst;

typedef struct {
    int stack[MAX_STACK_SIZE];
    int stack_size;
    int program_size;
    Inst *instructions;
}Machine;



#define DEF_INST_PUSH(x) {.type = INST_PUSH, .value = x}
#define DEF_INST_POP {.type = INST_POP }
#define DEF_INST_ADD {.type = INST_ADD }
#define DEF_INST_SUB {.type = INST_SUB }
#define DEF_INST_MUL {.type = INST_MUL }
#define DEF_INST_DIV {.type = INST_DIV }
#define DEF_INST_PRINT {.type = INST_PRINT } 


#endif // VIMA_H

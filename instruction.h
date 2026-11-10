#ifndef INSTRUCTION_H
#define INSTRUCTION_H

#include <stdint.h>

typedef enum {
    OP_MOV,
    OP_POP,
    OP_PUSH,
    OP_LABEL,
    OP_DB,
    OP_SECTION,
    OP_PRINT,
    OP_UNKNOWN,
}OpType;

typedef enum{
    OPERAND_NONE,
    OPERAND_IMMEDIATE,
    OPERAND_REGISTER,
    OPERAND_LABEL,
    OPERAND_MEMORY,

}OperandType;

typedef struct {
    uint64_t imed; // for immediate
    int reg ;
    char label[64];
    OperandType operandtype ;// Registers , immediate , .label or mem

}Operand;

// push 20
typedef struct {
    OpType op;
    int line;
    Operand operand;
    char label_name[64]; // if OP_LABEL .. implement this later
    uint64_t address;
}Instruction;


#endif


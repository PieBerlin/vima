#ifndef INSTRUCTION_H
#define INSTRUCTION_H

#include <stdint.h>

#include "./include/types.h"

typedef enum {
    OP_UNKNOWN,OP_HALT,OP_NOP,OP_ADD,OP_SUB,OP_MUL,OP_DIV,OP_MOD,
    OP_AND,OP_OR,OP_XOR,OP_NOT,OP_SHL,OP_SHR,
    OP_MOV,OP_LOADI,OP_LOAD,OP_STORE,OP_LOAD8,OP_STORE8,
    OP_CMP,OP_JMP,OP_JZ,OP_JNZ,OP_JE,OP_JNE,OP_JGT,OP_JLT,
    OP_CALL,OP_RET,OP_PUSH,OP_POP,OP_SYSCALL,OP_MALLOC,
    OP_ENTER, OP_LEAVE,OP_PRINT,
    OP_INC,OP_DEC,
    OP_LABEL, // "main:"
    OP_DB,
    OP_DW,
    OP_DQ,
    OP_ASCII,
    OP_ORG,
    OP_SECTION,
    /* Add more opcodes for future instruction */
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
    int8 reg;
    char label[32];
    OperandType operandtype ;// Registers , immediate , .label or mem

}Operand;

// push 20
typedef struct {
    OpType op;
    int line;
    Operand operand;
    char label_name[32]; // if OP_LABEL .. implement this later
    uint64_t address;
}Instruction;


#endif


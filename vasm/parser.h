#ifndef PARSER_H
#define PARSER_H

#include <stdint.h>

#include "lexer.h"


#define MAX_INSTRUCTIONS    1024

typedef enum {
    OP_MOV,
    OP_POP,
    OP_PUSH,
    OP_LABEL,
    OP_DB,
    OP_SECTION,
    OP_UNKNOWN,
}OpType;

typedef enum{
    IMMEDIATE,
    REGISTER,
    LABEL,
    MEMORY,

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

typedef struct {
    Instruction *instructions;
    int instr_count;

}Parser;



OpType optype_from_char(char *str);
void print_instructions(Parser *);
Parser *parser(Token *tokens);



#endif

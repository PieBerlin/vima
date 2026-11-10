#ifndef PARSER_H
#define PARSER_H

#include <stdint.h>

#include "lexer.h"
#include "../instruction.h"


#define MAX_INSTRUCTIONS    1024


typedef struct {
    Instruction *instructions;
    int instr_count;

}Parser;



OpType opcode_from_name(char *str);
void print_instructions(Parser *);
Parser *parser(Token *tokens);



#endif

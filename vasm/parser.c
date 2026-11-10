/* Parser.c */

#include "parser.h"




OpType opcode_from_name(char *name){
    if (strcmp(name,"push") == 0)
        return OP_PUSH;
    else if (strcmp(name,"pop") == 0)
        return OP_POP;


    return OP_UNKNOWN;

}
/*
typedef struct {
    OpType op;
    int line;
    Operand operand;
    char label_name[64]; // if OP_LABEL .. implement this later
    uint64_t address;
}Instruction;*/


void print_instructions(Parser *parser){
    int i = 0;
    while(i < parser->instr_count){
        printf("Opcode : %d Operand : %lu \n",
                parser->instructions[i].op,
                parser->instructions[i].operand.imed);
               //
        i++;
    }

}

Parser *parser(Token *tokens){
    Parser *parser = malloc(sizeof(Parser));
    parser->instructions = malloc(sizeof(Instruction) * MAX_INSTRUCTIONS);
    parser->instr_count = 0;
    int i = 0;
    int instruction_index = 0;
    while(tokens[i].type != END_OF_TOKENS){
        Instruction *inst = malloc(sizeof(Instruction));
        switch(tokens[i].type){
            case TYPE_IDENT:
                OpType type = opcode_from_name(tokens[i].value);
                if (type == OP_UNKNOWN){ 
                    fprintf(stderr, "Unknown opcode: %s line: %d",tokens[i].value,tokens[i].line);
                }
                inst->op = type;
                inst->line = tokens[i].line;

                // handle a push instruction 
                if (type == OP_PUSH){
                    if (tokens[i+1].type != TYPE_INT){
                        fprintf(stderr, "Error : Expected integer after %s , line %d\n"
                                ,tokens[i].value,tokens[i].line);
                    }
                    inst->operand.imed = atoi(tokens[i+1].value);
                    inst->operand.operandtype = OPERAND_IMMEDIATE;

                }

                // handle a pop instruction .. pop goes to a register 
                if (type == OP_POP){
                    if (tokens[i+1].type != TYPE_REG){
                        fprintf(stderr, "Error : Expected Register after %s , line %d\n"
                                ,tokens[i].value,tokens[i].line);
                    }
                    inst->operand.imed = atoi(tokens[i+1].value);
                    inst->operand.operandtype = OPERAND_REGISTER;

                }


                parser->instructions[instruction_index] = *inst;
                parser->instr_count += 1;
                instruction_index++;
                free(inst);

                i += 2;

                break;

            case TYPE_INT:
                break;
            case TYPE_REG:
                break;
            case TYPE_COMMA:
                break;
            case TYPE_COLON:
                break;
            case TYPE_PLUS:
                break;
            case TYPE_MINUS:
                break;
            case END_OF_TOKENS:
                break;
            case TYPE_LBRACKET:
                break;
            case TYPE_RBRACKET:
                break;
            case TYPE_DIRECTIVE:
                break;
            case TYPE_STRING:
                break;

        }


    }

    return parser;

}

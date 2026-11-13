/* Parser.c */

#include "parser.h"




OpType opcode_from_name(char *name){
    if (strcmp(name,"push") == 0)
        return OP_PUSH;
    else if (strcmp(name,"pop") == 0)
        return OP_POP;
    else if (strcmp(name,"mov") == 0)
        return OP_MOV;


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
        printf("Opcode : %d ",parser->instructions[i].op);
        switch(parser->instructions[i].operand.operandtype){
            case OPERAND_NONE:
                break;
            case OPERAND_IMMEDIATE:
                printf("Operand Immediate : %lu\n",parser->instructions[i].operand.imed);
                break;
            case OPERAND_REGISTER:
                printf("Operand Register : R%d\n",parser->instructions[i].operand.reg);
                break;
            case OPERAND_MEMORY:
                break;
            case OPERAND_LABEL:
                break;


        }
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
        char *reg = malloc(sizeof(char) * 3);
        switch(tokens[i].type){
            case TYPE_IDENT:
                OpType type = opcode_from_name(tokens[i].value);
                if (type == OP_UNKNOWN){ 
                    fprintf(stderr, "Unknown opcode: %s line: %d",tokens[i].value,tokens[i].line);
                    exit(1);
                }
                inst->op = type;
                inst->line = tokens[i].line;

                // handle a push instruction 
                if (type == OP_PUSH){
                    if (tokens[i+1].type != TYPE_INT && tokens[i+1].type != TYPE_REG ){
                        fprintf(stderr, "Error : Expected Integer or Register after %s , line %d\n"
                                ,tokens[i].value,tokens[i].line);
                        exit(1);
                    }
                    if (tokens[i+1].type == TYPE_INT){
                        inst->operand.imed = atoi(tokens[i+1].value);
                        inst->operand.operandtype = OPERAND_IMMEDIATE;
                    }else if (tokens[i+1].type == TYPE_REG){
                        strcpy(reg,tokens[i + 1].value);
                        inst->operand.reg = atoi(reg+1);
                        inst->operand.operandtype = OPERAND_REGISTER;

                    }


                    i += 2;
                    free(reg);
                }

                // handle a pop instruction .. pop goes to a register 
                else if (type == OP_POP){
                    if (tokens[i+1].type != TYPE_REG){
                        fprintf(stderr, "Error : Expected Register after %s , line %d\n"
                                ,tokens[i].value,tokens[i].line);
                        exit(1);
                    }
                    /*  Get the text in the type reg; 
                        Take the number part and put it int the operand.reg
                        Current usable registers will be 0-8
                    */
                    strcpy(reg,tokens[i + 1].value);
                    inst->operand.reg = atoi(reg+1);
                    inst->operand.operandtype = OPERAND_REGISTER;

                    i += 2;
                    free(reg);

                }
                /* Handle move instruction */
                else if (type == OP_MOV){
                    // check the next token 
                    if(tokens[i+1].type != TYPE_REG || tokens[i+2].type != TYPE_COMMA || 
                            tokens[i+3].type != TYPE_INT){
                        printf("Invalid arguments for mov instruction line %d\n",
                                tokens[i].line);
                        exit(1);
                    }
                    /*mov has two operands, well use reg and Immediate
                     * We'll keep in mind that mov has two arguments 
                     * the firdt is the register 
                     * the second in an Immediate value */
                    char *reg = tokens[i + 1].value;
                    inst->operand.reg = atoi(reg+1);
                    inst->operand.operandtype = OPERAND_REGISTER;
                    inst->operand.imed = atoi(tokens[i+3].value);
                    
                    i += 4;

                }


                parser->instructions[instruction_index] = *inst;
                parser->instr_count += 1;
                instruction_index++;
                free(inst);


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

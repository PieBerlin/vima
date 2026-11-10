#include "vima.h"
#include "./vasm/lexer.h"
#include "./vasm/parser.h"
#include "./vasm/generatebytes.h"

Instruction program[] = {
    { .op = OP_PUSH, .operand.imed = 9, .operand.operandtype = OPERAND_IMMEDIATE},
    { .op = OP_PUSH, .operand.imed = 7, .operand.operandtype = OPERAND_IMMEDIATE}
}; 
#define PROGRAM_SIZE (sizeof(program)/sizeof(program[0]))


void push(Machine *machine,int value){
    if (machine->stack_size >= MAX_STACK_SIZE){
        fprintf(stderr, "ERROR: Stack is Full\n");
        exit(1);
    }
    machine->stack[machine->stack_size] = value;
    machine->stack_size++;
}

int pop(Machine *machine){
    if (machine->stack_size <= 0){
        fprintf(stderr, "ERROR: Stack is Empty\n");
        exit(1);
    }
    machine->stack_size--;
    return machine->stack[machine->stack_size];
}


void print_stack(Machine *machine){
    printf("---------END OF STACK------------\n");
    for (int i = 0; i < machine->stack_size; i++){
        printf("%d#\t%d\n",i+1,machine->stack[i]);
    }
    printf("-----------TOP OF STACK----------\n");
}

/* void write_program_to_file(char *file_path){
    FILE *file  = fopen(file_path,"wb");

    if (file == NULL){
        fprintf(stderr, "ERROR: Could not write to file %s\n",file_path);
        exit(1);
    }

    fwrite(program,sizeof(program[0]),PROGRAM_SIZE,file);

    fclose(file);

}*/


/* This functions reads instructions in bytes from a file.
 * The bytes instuctions are then run in the virtual machine */
void read_program_from_file(Machine *machine,char *file_path){
    FILE  *file = fopen(file_path,"rb");
    if (file == NULL){
        fprintf(stderr, "ERROR: Could not read from file %s\n",file_path);
        exit(1);
    }

    Instruction *instruction = malloc(sizeof(Instruction) * MAX_INSTRUCTION_SIZE);

    fseek(file,0,SEEK_END);
    int length = ftell(file);
    fseek(file,0,SEEK_SET);

    fread(instruction,sizeof(Instruction),length / sizeof(Instruction),file);

    machine->program_size = length / sizeof(Instruction); // 8 is size of each instruction
    machine->instructions = instruction;

    fclose(file);

}
void run_instruction(Machine *machine){
    for (size_t ip = 0; ip< PROGRAM_SIZE; ip++){
            switch (machine->instructions[ip].op) {
                case OP_PUSH:
                    push(machine,machine->instructions[ip].operand.imed);
                    break;
                case OP_POP:
                    break;
                case OP_MOV:
                    break;
                case OP_PRINT:
                    break;
                default:
                    break;
            }
        }

}
int main(){

    Machine *machine = init_machine();

    Token *tokens = lexer("test.vasm");
    print_tokens(tokens);

    Parser *p = parser(tokens);
    print_instructions(p);

    write_program_to_file(p,"test.vm");
    read_program_from_file(machine,"test.vm");
    run_instruction(machine);
    print_stack(machine);

    return 0;

}

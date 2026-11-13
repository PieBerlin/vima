#include "vima.h"
#include "./vasm/lexer.h"
#include "./vasm/parser.h"
#include "./vasm/generatebytes.h"
#include "./assembly.h"



void print_stack(Machine *machine){
    printf("---------BOTTOM OF STACK------------\n");
    for (uint64_t i = 0; i < machine->sp; i++){
        printf("%lu#\t%lu\n",i+1,machine->stack[i]);
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
    for (uint64_t ip = 0; ip < machine->program_size; ip++){
        int reg;
            switch (machine->instructions[ip].op) {
                case OP_PUSH:
                    push(machine,machine->instructions[ip].operand.imed);
                    break;
                case OP_POP:
                    reg = machine->instructions[ip].operand.reg;
                    machine->regs[reg] = pop(machine);
                    break;
                case OP_MOV:
                    reg = machine->instructions[ip].operand.reg;
                    uint64_t value = machine->instructions[ip].operand.imed;
                    mov(machine,reg,value);
                    break;
                case OP_PRINT:
                    break;
                default:
                    break;
            }
        }

}

void print_registers(Machine *machine){
    printf("\n\n");
    printf("############## REGISTERS #################\n");

    for (int i = 0; i < MAX_REGISTERS; i++){
        printf("#\tRegister R%d\tValue: %lu\n",i,machine->regs[i]);
    }
    printf("##########################################");
    printf("\n\n");

}
int main(){

    Machine *machine = init_machine();

    Token *tokens = lexer("test.vasm");
    print_tokens(tokens);

    (void)machine;

    Parser *p = parser(tokens);
    print_instructions(p);
    //
    write_program_to_file(p,"test.vm");

    free(p);

    read_program_from_file(machine,"test.vm");
    run_instruction(machine);
    print_stack(machine);
    print_registers(machine);

    return 0;

}

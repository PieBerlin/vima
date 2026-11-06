#include "vima.h"
#include "./vasm/lexer.h"

Inst program[] = {
    DEF_INST_PUSH(5),
    DEF_INST_PUSH(10),
    DEF_INST_ADD,
    DEF_INST_PRINT
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
    for (int i = 0; i < machine->stack_size; i++){
        printf("%d#\t%d\n",i+1,machine->stack[i]);
    }
}

void write_program_to_file(char *file_path){
    FILE *file  = fopen(file_path,"wb");

    if (file == NULL){
        fprintf(stderr, "ERROR: Could not write to file %s\n",file_path);
        exit(1);
    }

    fwrite(program,sizeof(program[0]),PROGRAM_SIZE,file);

    fclose(file);

}

void read_program_from_file(Machine *machine,char *file_path){
    FILE  *file = fopen(file_path,"rb");
    if (file == NULL){
        fprintf(stderr, "ERROR: Could not read from file %s\n",file_path);
        exit(1);
    }

    Inst *instruction = malloc(sizeof(Inst) * MAX_STACK_SIZE);

    fseek(file,0,SEEK_END);
    int length = ftell(file);
    fseek(file,0,SEEK_SET);

    fread(instruction,sizeof(Inst),length / 8,file);

    machine->program_size = length / 8; // 8 is size of each instruction
    machine->instructions = instruction;

    fclose(file);

}
void run_instruction(Machine *machine){
    int a,b;
    for (size_t ip = 0; ip< PROGRAM_SIZE; ip++){
            switch (machine->instructions[ip].type) {
                case INST_PUSH:
                    push(machine,machine->instructions[ip].value);
                    break;
                case INST_POP:
                    pop(machine);
                    break;
                case INST_ADD:
                    a = pop(machine);
                    b = pop(machine);
                    push(machine,a + b);
                    break;
                case INST_SUB:
                    a = pop(machine);
                    b = pop(machine);
                    push(machine,b - a);
                    break;
                case INST_MUL:
                    a = pop(machine);
                    b = pop(machine);
                    push(machine,a * b);
                    break;
                case INST_DIV:
                    a = pop(machine);
                    b = pop(machine);
                    push(machine,b / a);
                    break;
                case INST_PRINT:
                    printf("%d\n",pop(machine));
                    break;
                default:
                    break;
            }
        }

}
int main(){

    Machine *machine = init_machine();
    write_program_to_file("test.vm");
    read_program_from_file(machine,"test.vm");
    run_instruction(machine);
    print_stack(machine);

    Token *tokens = lexer("test.vasm");
    print_tokens(tokens);

    return 0;

}

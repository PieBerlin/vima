#include "symbol_table.h"
#include "instruction.h"


void create_symbol_table(SYMBOL_TABLE *symbol_table,Machine *machine){
    printf("Here\n");
    SYMBOL_TABLE *item = malloc(sizeof(SYMBOL_TABLE));
    int i = 0;
    while(i < machine->program_size){
        if (machine->instructions[i].op == OP_LABEL){
            printf(" ---%s\n",machine->instructions[i].label_name);
            strcpy(item->label,machine->instructions[i].label_name);
            printf(" ---%s\n",item->label);
            item->value = machine->instructions[i].address;
            printf("item %d\n",item->value);
            symbol_table[i] = *item;
            symbol_table[i] = {.label = "me",.value = 2};
        }
            i++;

    }
    free(item);
}
void check_for_label(){

}

void print_symbol_table(SYMBOL_TABLE *symbol_table){
    int i = 0;
    while(*symbol_table[i].label){
        printf("Here %s\n",symbol_table[i].label);
        printf("Label: %s Address: %d\n",symbol_table[i].label,symbol_table[i].value);
        i++;
    }

}

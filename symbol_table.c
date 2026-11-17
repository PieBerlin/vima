#include "symbol_table.h"
#include "instruction.h"


void create_symbol_table(SYMBOL_TABLE *symbol_table,Machine *machine){
    SYMBOL_TABLE *item = malloc(sizeof(SYMBOL_TABLE));
    int i = 0;
    int table_index = 0;
    while(i < machine->program_size){
        if (machine->instructions[i].op == OP_LABEL){
            strcpy(item->label,machine->instructions[i].label_name);
            item->value = machine->instructions[i].address;
            symbol_table[table_index] = *item;
            table_index += 1;
        }
            i++;

    }
    free(item);
}
int check_for_label(SYMBOL_TABLE *symbol_table,char *name){
    int i = 0;
    while (*symbol_table[i].label){
        if (strcmp(symbol_table[i].label, name) == 0){
            return symbol_table[i].value;
        }
        i++;

    }
    return -1;
}

void print_symbol_table(SYMBOL_TABLE *symbol_table){
    int i = 0;
    while(*symbol_table[i].label){
        printf("Label: %s Address: %d\n",symbol_table[i].label,symbol_table[i].value);
        i++;
    }

}

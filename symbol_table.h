#ifndef SYMBOL_TABLE_H
#define SYMBOL_TABLE_H

#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#include "./instruction.h"
#include "vima.h"

typedef struct SYMBOL_TABLE {
    char label[64];/* Stores the label name */
    int value; /* Stores the address wich is instruction number */

}SYMBOL_TABLE;

void create_symbol_table(SYMBOL_TABLE *symbol_table,Machine *machine);
void check_for_label();
void print_symbol_table(SYMBOL_TABLE *symbol_table);
#endif

#ifndef SYMBOL_TABLE_H
#define SYMBOL_TABLE_H

typedef struct SYMBOL_TABLE {
    char *label;/* Stores the label name */
    int value; /* Stores the address wich is instruction number */

}SYMBOL_TABLE;

void create_symbol_table();
void check_for_label();
#endif

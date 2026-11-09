#ifndef LEXER_H
#define LEXER_H 
#include <stdio.h>
#include <ctype.h>
#include <string.h>
#include <stdlib.h>
#include <assert.h> 

typedef enum {
    TYPE_IDENT, // keywords
    TYPE_REG,// Registers
    TYPE_COMMA,// ,
    TYPE_COLON, //:
    TYPE_LBRACKET, //[
    TYPE_RBRACKET, // ]
    TYPE_PLUS,// +
    TYPE_MINUS,// -
    TYPE_DIRECTIVE, /*.text .data .db .org*/
    TYPE_INT,
    TYPE_STRING, // "hello"
    END_OF_TOKENS,

}TokenType;

typedef struct Token{
    TokenType type;
    int line;
    int col; /* word number in a line*/
    char *value;
}Token;

void print_tokens(Token *tokens);
Token *lexer(char*);

#endif // !LEXER_H:

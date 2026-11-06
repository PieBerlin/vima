#ifndef LEXER_H
#define LEXER_H 
#include <stdio.h>
#include <ctype.h>
#include <string.h>
#include <stdlib.h>
#include <assert.h> 

typedef enum {
    TYPE_INVALID = -1,
    TYPE_NOP = 0,/*No operation */
    TYPE_MOV,/*Move value to , from ,between registers/memory */
    TYPE_CMOV,/* Conditional mov */
    TYPE_PUSH,/* Push value to stack */
    TYPE_POP,/*Pop value from stack */
    TYPE_BSWAP,/*Byte swap*/
    TYPE_XCHG,/*Exchange*/
    TYPE_INC,/* Increeament */
    TYPE_DEC,/* Decreament*/
    TYPE_NEG,/*Negate*/
    TYPE_CMP,/*Compare*/
    TYPE_ADD,/*Add*/
    TYPE_ADDC, /*ADD with carry*/
    TYPE_SUB,/*Subtract*/
    TYPE_SUBC,/*Subtract with carry*/
    TYPE_MUL,/*Multiply*/
    TYPE_IMUL,/*Unsigned Multiplication */
    TYPE_DIV,/* Division */
    TYPE_IDIV,/*Unsigned divition */
    TYPE_AND,/*ADD Bitwise Operation */
    TYPE_OR,/**/
    TYPE_XOR,/**/
    TYPE_NOT,/**/
    TYPE_SHR,/*SHift right*/
    TYPE_SHL,/*SHift Left*/
    TYPE_SAR,/*Shift Arithmetic */
    TYPE_SAL,/**/
    TYPE_ROR,/*Rotate right*/
    TYPE_ROL,/*Rotate Left*/
    TYPE_RCR,/**/
    TYPE_RCL,/**/
    TYPE_BT,/*Bit Test*/
    TYPE_BTS,/* Bit test and set */
    TYPE_BTR,/*Bit test and reset */
    TYPE_JMP,/*Unconditional jump */
    TYPE_JE,/*Jump Equals*/
    TYPE_JNE,/*Jump not equal */
    TYPE_JC,/*Jump carry*/
    TYPE_JNC,/*Jump  not carrry*/
    TYPE_J,/*Other jump*/
    TYPE_LOOP,/**/
    TYPE_LOOPE, /*Loop with ECX*/
    TYPE_LOOPNE,/**/
    TYPE_CALL, /*Call subroutine*/
    TYPE_RET,/**/
    TYPE_CPUID,/* CPU information */
    TYPE_PRINT,/**/
    TYPE_HALT,/**/
    TYPE_INT,
    TYPE_SEPARATOR,
    END_OF_TOKENS,

}TokenType;

typedef struct Token{
    TokenType type;
    int line;
    int character; /* word number in a line*/
    char *value;
}Token;

void print_tokens(Token *tokens);
Token *lexer(char*);

#endif // !LEXER_H:

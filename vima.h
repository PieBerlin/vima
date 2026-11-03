#ifndef VIMA_H
#define VIMA_H

#include <stdio.h>
#include  <stdlib.h>
#include <string.h>
#include <assert.h>

#define MAX_STACK_SIZE 1024

typedef enum {
    INST_NOP,/*No operation */
    INST_MOV,/*Move value to , from ,between registers/memory */
    INST_CMOV,/* Conditional mov */
    INST_PUSH,/* Push value to stack */
    INST_POP,/*Pop value from stack */
    INST_BSWAP,/*Byte swap*/
    INST_XCHG/*Exchange*/
    INST_INC,/* Increeament */
    INST_DEC,/* Decreament*/
    INST_NEG,/*Negate*/
    INST_CMP,/*Compare*/
    INST_ADD,/*Add*/
    INS_ADDC, /*ADD with carry*/
    INST_SUB,/*Subtract*/
    INS_SUBC,/*Subtract with carry*/
    INST_MUL,/*Multiply*/
    INST_IMUL,/*Unsigned Multiplication */
    INST_DIV,/* Division */
    INST_IDIV,/*Unsigned divition */
    INST_AND,/*ADD Bitwise Operation */
    INST_OR,/**/
    INST_XOR,/**/
    INST_NOT,/**/
    INST_SHR,/*SHift right*/
    INST_SHL,/*SHift Left*/
    INST_SAR,/*Shift Arithmetic */
    INST_SAL,/**/
    INST_ROR,/*Rotate right*/
    INST_ROL,/*Rotate Left*/
    INST_RCR,/**/
    INST_RCL,/**/
    INST_BT,/*Bit Test*/
    INST_BTS,/* Bit test and set */
    INST_BTR,/*Bit test and reset */
    INST_JMP,/*Unconditional jump */
    INST_JE,/*Jump Equals*/
    INST_JNE,/*Jump not equal */
    INST_JC,/*Jump carry*/
    INST_JNC,/*Jump  not carrry*/
    INST_J,/*Other jump*/
    INST_LOOP,/**/
    INST_LOOPE, /*Loop with ECX*/
    INST_LOOPNE/**/
    INST_CALL, /*Call subroutine*/
    INST_RET,/**/
    INST_CPUID,/* CPU information */
    INST_PRINT,/**/
    INST_HALT,/**/

}Inst_Set;
typedef struct Inst{
    Inst_Set type;
    int value;

}Inst;

typedef struct {
    int stack[MAX_STACK_SIZE];
    int stack_size;
    int program_size;
    Inst *instructions;
}Machine;



#define DEF_INST_PUSH(x) {.type = INST_PUSH, .value = x}
#define DEF_INST_POP {.type = INST_POP }
#define DEF_INST_ADD {.type = INST_ADD }
#define DEF_INST_SUB {.type = INST_SUB }
#define DEF_INST_MUL {.type = INST_MUL }
#define DEF_INST_DIV {.type = INST_DIV }
#define DEF_INST_PRINT {.type = INST_PRINT } 


#endif // VIMA_H

#include "generatebytes.h"
#include "../instruction.h"



/* This function write bytes to a file which is will read by a vm to run them */
void write_program_to_file(Parser *parser,char *file_path){
    FILE *file  = fopen(file_path,"wb");

    if (file == NULL){
        fprintf(stderr, "ERROR: Could not write to file %s\n",file_path);
        exit(1);
    }
    printf("--%d\n",parser->instr_count);
    printf("%lu\n",sizeof(Instruction));

    fwrite(parser->instructions,sizeof(Instruction),parser->instr_count,file);

    fclose(file);

}

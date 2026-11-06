#include "lexer.h"


FILE *open_file(char *filename,int *file_length){
    FILE *file = fopen(filename,"r");

    if (!file){
        fprintf(stderr,"Unable to open file %s",filename);
    }

    fseek(file,0,SEEK_END);
    *file_length = ftell(file);
    fseek(file,0,SEEK_SET);

    return file;
}

TokenType check_keyword(char *word){
    if (strcmp(word,"push") == 0)
        return TYPE_PUSH;
    else if(strcmp(word,"pop") == 0)
        return TYPE_POP;
    else 
        return TYPE_INVALID;

}

Token *generate_keyword(char *buffer,int *current_index){
    char *word = malloc(sizeof(char) * 32);
    word[0]= buffer[*current_index];
    int index = 1;
    *current_index += 1;
    while (isalpha(buffer[*current_index])){
        word[index] = buffer[*current_index];
        *current_index += 1;
        index++;
    }
    word[index] = '\0';
    // printf("index %d",index);
    // printf("%s %d\n",word,strlen(word));
    Token *token = malloc(sizeof(Token));
    
    TokenType type = check_keyword(word);
    // assert(type != TYPE_INVALID && "Error Invalid instruction");
    token->type = type;
    token->value = malloc(sizeof(char) * index);
    strcpy(token->value,word);
    //
    free(word);

    return token;
}

Token *generate_number(char *buffer, int *current_index){
    char *word = malloc(sizeof(char) * 32);
    word[0]= buffer[*current_index];
    int index = 1;
    *current_index += 1;
    while (isdigit(buffer[*current_index])){
        word[index] = buffer[*current_index];
        *current_index += 1;
        index++;
    }
    word[index] = '\0';
    // printf("index %d",index);
    // printf("%s %d\n",word,strlen(word));
    Token *token = malloc(sizeof(Token));
    
    token->type = TYPE_INT;
    token->value = malloc(sizeof(char) * index);
    strcpy(token->value,word);
    
    free(word);

    return token;
}

void print_tokens(Token *tokens){
    int index = 0;
    while(tokens[index].type != END_OF_TOKENS){
        switch(tokens[index].type){
            case TYPE_PUSH:
                printf("TOKEN TYPE PUSH : VALUE: %s LINE: %d, CHARACTER : %d\n "
                       , tokens[index].value,
                        tokens[index].line,tokens[index].character);
                index++;
                break;
            case TYPE_INT:
                printf("TOKEN TYPE INT : VALUE: %s LINE: %d, CHARACTER : %d\n "
                       , tokens[index].value,
                        tokens[index].line,tokens[index].character);
                index++;
                break;
            case TYPE_POP:
                printf("TOKEN TYPE POP : VALUE: %s LINE: %d, CHARACTER : %d\n "
                       , tokens[index].value,
                        tokens[index].line,tokens[index].character);
                index++;
                break;
            case TYPE_SEPARATOR:
                printf("TOKEN TYPE SEPARATOR : VALUE %s LINE %d, CHARACTER : %d\n",
                        tokens[index].value,tokens[index].line,tokens[index].character);
                index++;
                break;
            default:
                index++;
                break;
        }

    }
    return;
        
}

Token *generate_separator(char value){
    Token *token = malloc(sizeof(Token));
    token->type = TYPE_SEPARATOR;
    token->value = malloc(sizeof(char) * 2);
    token->value[0] = value;
    token->value[1] = '\0';

    return token;
}

Token *lexer(char *filename){
    int file_length;
    FILE *file = open_file(filename,&file_length);

    char *buffer = malloc((sizeof(char) * file_length) + 1);
    fread(buffer,1,file_length,file);
    buffer[file_length + 1] = '\0';
    fclose(file);


    // printf("%s\n",buffer);
    int number_of_tokens = 1024;
    Token *tokens = malloc(sizeof(Token) * number_of_tokens);
    int tokens_index = 0;

    int *current_index = malloc(sizeof(int));
    *current_index = 0;
    
    int line = 1;
    int character = 1;

    while (buffer[*current_index] != '\0'){
        Token *token; 
        if (buffer[*current_index] == '\n'){
            line++;
            character = 1;
        }
        if (isalpha(buffer[*current_index])){
            token = generate_keyword(buffer,current_index);
            token -> character = character;
            token->line = line;
            tokens[tokens_index] = *token;
            character++;
            tokens_index++;
            free(token);
        }else if(isdigit(buffer[*current_index])){
            token = generate_number(buffer,current_index);
            token->character = character;
            token->line = line;
            tokens[tokens_index] = *token;
            character++;
            tokens_index++;
            free(token);
        }else if(buffer[*current_index] == ',') {
            printf("We get here\n");
            token = generate_separator(buffer[*current_index]);
            token->character = character;
            token->line = line;
            tokens[tokens_index] = *token;
            character++;
            tokens_index++;
            *current_index += 1;
            free(token);

        } else {
            *current_index += 1;

        }

    }
    Token *end_of_tokens = malloc(sizeof(Token));
    end_of_tokens->type = END_OF_TOKENS;


    tokens[tokens_index] = *end_of_tokens;


    free(end_of_tokens);
    free(current_index);
    return tokens;
}

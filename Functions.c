#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>

#define WORD 30
#define TXT 1024
char word[WORD];
char text[TXT];

void initialization(){
    
    printf("please enter a word no more than 30 characters:");
    gets(word);
    
    printf("please enter text with no more than 1024 characters:");
    gets(text);
}
void gematry(){
    char *cptr = NULL;
    //memory allocation to word
    cptr = (char*)malloc(sizeof(char));
    //check if malloc realy allocate 
    if(cptr == NULL){
        return ;
    }
    //run over the text and take words 
    for (int i=0;i<strlen(text); i++){
        char ch = text[i]; 
        //check if the char is letter 
        if(isalpha(ch)){
        // allocate (1) memory for this letter
        cptr = realloc(cptr,((strlen(cptr)+1)*sizeof(char)));
        
        //connect the letter to this word 
        strncat(cptr, &ch, 1);
        if(cptr == NULL){
            return ;}
        }
        else {
        //check if cptr not empty
        if(cptr[0] != '\0'){
        //check if cptr equal to word 
        if(Gematria_value(cptr) == Gematria_value(word)){
            //printf("are the same");
            printf("%s /n", cptr);
            }
        cptr[0]= '\0';
        memset(cptr,0,strlen(cptr));
        }

    }
}
free(cptr);
}
int Gematria_value(char *str){
int Value = 0;
int i =0;
while(str[i])
{
    char ch = str[i];

    if (ch >= 'A' && ch <= 'Z')
    {
        Value += ch - 'A' + 1;
    }
    else if (ch >= 'a' && ch <= 'z')
    {
        Value += ch - 'a' + 1;
    }
    i++;
}
}
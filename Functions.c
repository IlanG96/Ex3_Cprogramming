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
    fgets(word,WORD,stdin);
    
    printf("please enter text with no more than 1024 characters::");
    fgets(text,TXT,stdin);
}

int Gematria_value(char *str){
int Value = 0;
int counter = 0;
for (int i = 0; i < strlen(str); i++)
{
    char ch = str[i];
    if (ch >= 'A' && ch <= 'Z')
    {
        Value += ch - 'A' + 1;
        counter++;
    }
    else if (ch >= 'a' && ch <= 'z')
    {
        Value += ch - 'a' + 1;
        counter++;
     } 
    else if(isalpha(ch) == 0 && counter == 0){
         Value++;
    }
}
return Value;
}
void gematry(){
    char *cptr = NULL;
    cptr = (char*)malloc(sizeof(char));
    if(cptr == NULL){
        return ;
    }
    int gem_word=Gematria_value(word);
    for (int i=0;i<strlen(text); i++){
        char ch = text[i];
        cptr = realloc(cptr,((strlen(cptr)+1)*sizeof(char)));
        if(cptr == NULL){return ;}
        strncat(cptr, &ch, 1);

        if(Gematria_value(cptr) == gem_word){
             printf("~%s", cptr);
             memmove(cptr, cptr+1, strlen(cptr));
             cptr = realloc(cptr, strlen(cptr));
            }
        else{
            while(Gematria_value(cptr) > gem_word){
                memmove(cptr, cptr+1, strlen(cptr));
                cptr = realloc(cptr,((strlen(cptr)+1)*sizeof(char)));}
            if(Gematria_value(cptr) == gem_word){
                printf("~%s", cptr);
                memmove(cptr, cptr+1, strlen(cptr));
                cptr = realloc(cptr,((strlen(cptr)+1)*sizeof(char)));;
                
            }
        }
    }   
free(cptr);
}

void Atbash(){
    
} 

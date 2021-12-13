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
    int counter=0;
    char *cptr = NULL;
    cptr = (char*)malloc(sizeof(char));
    if(cptr == NULL){
        return ;
    }
    int gem_word=Gematria_value(word);
    for (int i=0;i<strlen(text); i++){
        if (text[i]=='~')
        {
            break;
        }
        
        char ch = text[i];
        cptr = realloc(cptr,((strlen(cptr)+1)*sizeof(char)));
        if(cptr == NULL){return ;}
        strncat(cptr, &ch, 1);

        if(Gematria_value(cptr) == gem_word){
            if (counter==0){
                printf("%s", cptr);
            }
            else{
             printf("~%s", cptr);}
             memmove(cptr, cptr+1, strlen(cptr));
             cptr = realloc(cptr, strlen(cptr));
             counter++;
            }
        else{
            while(Gematria_value(cptr) > gem_word){
                memmove(cptr, cptr+1, strlen(cptr));
                cptr = realloc(cptr,((strlen(cptr)+1)*sizeof(char)));}
            if(Gematria_value(cptr) == gem_word){
                if (counter==0){
                printf("%s", cptr);
            }
            else{
             printf("~%s", cptr);}
                memmove(cptr, cptr+1, strlen(cptr));
                cptr = realloc(cptr,((strlen(cptr)+1)*sizeof(char)));
                counter++;
                
            }
        }
    } 
printf("\n");
free(cptr);
}

void reverse_str(char *str1)  
{    
    int temp;        
    for (int i = 0; i < strlen(str1)/2; i++)  
    {   
        temp = str1[i];  
        str1[i] = str1[strlen(str1) - i - 1];  
        str1[strlen(str1) - i - 1] = temp;  
    }  
}  

void Atbash_func(char *str){
    for (int i = 0; i < strlen(str); i++)
    {
        char ch=str[i];
            if (ch >= 'A' && ch <= 'Z')
    {
        str[i]='Z'-(ch-'A');
    }
    else if (ch >= 'a' && ch <= 'z')
    {
         str[i]='z'-(ch-'a');
     } 
    }
}

void Atbash(){
char* original=(char*)malloc(strlen(word));
char* word2=(char*)malloc(strlen(word));
strcpy(original,word);
strcpy(word2,word);
reverse_str(word2);
Atbash_func(original);
Atbash_func(word2);
//printf("%s,%s \n", word2, original);
int positions[strlen(word)]; // saves the positions of word 
int k=0;
    for(int i=0; i<strlen(text) - strlen(word); i++)
    {
        printf("%s,%s \n", word, original);
        int found = 1;
        for(int j=0; j<3; j++)
        {
            printf("%s,%s \n", *word, original);
            if(text[i + j] != word2[j] )
            {
                found = 0;
                break;
            }
        }
                if(found == 1)
        {
            positions[0] = i ;
            k++;
        }
    }

  
     printf("%d\n ", positions[0]);
  
//printf("%s\n %s", word,original);
}



    



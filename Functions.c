#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>
#include "Functions.h"

#define WORD 30
#define TXT 1024
static char word[WORD];
static char text[TXT];
static char Wordatbash[WORD];
static char reverseAtbash[WORD];

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

void reverse_str(char *Wordatbash)  
{    
    int temp;        
    for (int i = 0; i < strlen(Wordatbash)/2; i++)  
    {   
        temp = Wordatbash[i];  
        reverseAtbash[i] = Wordatbash[strlen(Wordatbash) - i - 1];  
        reverseAtbash[strlen(Wordatbash) - i - 1] = temp;  
    } 
}  

void Atbash_func(char *word){
    for (int i = 0; i < strlen(word); i++)
    {
        char ch=word[i];
        if (ch >= 'A' && ch <= 'Z')
        {
            Wordatbash[i]='Z'-(ch-'A');
        }
    else if (ch >= 'a' && ch <= 'z')
        {
         Wordatbash[i]='z'-(ch-'a');
        } 
    
    }
}

void Atbash(){
Atbash_func(word);
reverse_str(Wordatbash);
int tilda = 1;
for (int i = 0; i < strlen(text)-strlen(word)+1; i++)
{
   char *cptr1 = NULL;
   cptr1 = (char*)malloc(sizeof(char));
   char* cptr2=NULL;
   cptr2 = (char*)malloc(sizeof(char));
    int flag1=1;
    int flag2=1;   
    int num=0;
   for (int j = 0; j < strlen(Wordatbash); j++)
   {
       if(text[i]==' '){
        flag1 =0;
        flag2=0;
        break;}
       if(text[i+num] == ' '){
           num++;
           j--;
       }
       else {
       if (Wordatbash[j]==text[i+num]&&flag1==1)
       {
        
        cptr1 = realloc(cptr1,((strlen(cptr1)+1)*sizeof(char)));
        if(cptr1 == NULL){return ;}
        strncat(cptr1, &text[i+num], 1);
       }
       else{
           flag1=0;
       }
        if (reverseAtbash[j]==text[i+num]&&flag2==1)
       {
        cptr2 = realloc(cptr2,((strlen(cptr2)+1)*sizeof(char)));
        if(cptr2 == NULL){return ;}
        strncat(cptr2, &text[i+num], 1);
       }
       else{
           flag2=0;
       }
       num++;

   }
   }
   //printf("flag1=%d, flag2=%d",flag1,flag2);
   if(flag1==1){
       if(tilda==1){
      printf("%s",cptr1); 
      tilda =0;
   }else{
       printf("~%s",cptr1);
   }
    }
   if (flag2==1){
       if(tilda ==1){
      printf("%s",cptr2); 
       tilda =0;
       }else {
      printf("~%s",cptr2);
   }   
   }
   
   
}
printf("\n");
}


int * intdeep(int const * src, size_t len)
{
   int * p = (int*)calloc(len , sizeof(int));
   memcpy(p, src, len * sizeof(int));
   return p;
}
void Anagram(){
    int counter = 1;
    int word_len = strlen(word);
     int *count_word = (int*)calloc(128,sizeof(int));
     for(int i=0; i<word_len; i++){
         count_word[word[i]]++;
     }
     char *cptr = NULL;
     cptr = (char*)malloc(sizeof(char));
     int text_len = strlen(text);
     for (int i = 0; i < text_len; i++)
     {
         cptr[0] = '\0';
         int t=0; 
         int * temp = intdeep( count_word , 128);
         int num=i;
         for (int j = i; j < i+word_len; j++)
         {
        if(text[i]==' '){
            counter =0;
        break;}
          if(text[num] == ' '){
           num++;
           j--;
       }
             else{
              if(temp[text[num]]!=0){
                cptr = realloc(cptr,((strlen(cptr)+1)*sizeof(char)));
                strncat(cptr, &text[num], 1);
                 temp[text[num]]--;
                 num++;
                }
             else {
                 num++;
                 break;
             }    
             }
         }  
     temp[10]=0;
     int flag=1;
     
    for (int k = 0; k < 128; k++)
     {
         if(temp[k]!=0)flag=0;
     }
     if(flag==1){
         if(counter == 1 )
         printf("%s",cptr);
         else 
         printf("~%s",cptr);
         counter=0;}
     for (int i = 0; i < 128; i++)
     {
         temp[i] = 0 ; 
     }
     }
     printf("\n");
}



    



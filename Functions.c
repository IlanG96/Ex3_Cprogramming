#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>

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

int PlaceFinder(char *theword,int *positionsptr,int k){
    int counter=0;
 for(int i=0; i<strlen(text) - strlen(word)+1; i++)
    {
        for(int j=0; j<strlen(word)-1; j++)
        {
            char textC=text[i + j];
            char curr_word=theword[j];
            //printf("%c,%c \n", textC, curr_word);
            if(textC != curr_word )
            {
                counter=0;
                //printf("restcounter %d\n", counter);
                //printf("J %d\n", j);

                break;
            }
            else{
                counter++;
               // printf("counter++ %d\n", counter);
                // printf("J %d\n", j);


            }
        }
                if(counter == strlen(word)-1)
        {
            positionsptr = realloc(positionsptr,  (k+1)* sizeof(int));
            //printf("counter equal  %d\n", counter);   
            *(positionsptr+k) = i;
            k++;
            counter=0;
        }
    }
    return k;

}

void Atbash(){
Atbash_func(word);
reverse_str(Wordatbash);
 int *positionsptr;
positionsptr = (int*) malloc(1 * sizeof(int));
int k=0;
k=PlaceFinder(reverseAtbash,positionsptr,k);
k=PlaceFinder(Wordatbash,positionsptr,k);
 for (int i = 0; i < k; i++)
 {

    printf("%d, ", *(positionsptr+i));

 }
 printf("\n, ");
 
    
     //printf("%d,%d,%d,%d\n ", *positionsptr,*(positionsptr+1),*(positionsptr+2),*(positionsptr+3));
     free(positionsptr);
}

int * intdeep(int const * src, size_t len)
{
   int * p = (int*)calloc(len , sizeof(int));
   memcpy(p, src, len * sizeof(int));
   return p;
}
void Anagram(){

    int word_len = strlen(word);
     int *count_word = (int*)calloc(128,sizeof(int));
     int * temp = intdeep( count_word , 128);
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
         for (int j = i; j < i+word_len; j++)
         {
             if(temp[text[j]]!=0){
                cptr = realloc(cptr,((strlen(cptr)+1)*sizeof(char)));
                strncat(cptr, &text[j], 1);
                t++;
              if( text[j] != ' '){
                 temp[text[j]]--;}
              else {
            //cptr[t] = ' ';
            memset(cptr+strlen(cptr),' ',1);
              j--;
                }
             }
             else {
                 break;
             }    
     }    
     temp[10]=0;
     int flag=1;
     for (int k = 0; k < 128; k++)
     {
         if(temp[k]!=0)flag=0;
     }
     if(flag==1){printf("angram =%s\n",cptr); }
     for (int i = 0; i < 128; i++)
     {
         temp[i] = 0 ; 
     }
     }
}



    



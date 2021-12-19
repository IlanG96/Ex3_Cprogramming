#include <stdio.h>
#include "Functions.h"

#define WORD 30
#define TXT 1024
static char word[WORD];
static char text[TXT];

int main(){
     initialization();
     printf("Gematria Sequences: ");
     gematry();
     printf("Atbash Sequences: ");
     Atbash();
     printf("Anagram Sequences: ");
     Anagram();
     return 0;
}

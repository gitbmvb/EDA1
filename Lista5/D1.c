#include <stdio.h>
#include <string.h>

int final = 0;

void composeSubstring(char * address, char * reference, int beginning, int length, int acc){
    if(acc >= length){
        *address = '\0';
        return;    
    }
    *address = *(reference + beginning + acc);
    acc++;
    composeSubstring(&address[1], reference, beginning, length, acc);
}

void BiggestSubstring(char * text, char * reference, int reference_length, int acc, int beginning, int flag){
    char aux[reference_length];
    composeSubstring(aux, reference, beginning, reference_length, 0);

    if(strcmp(aux, reference) == 0 && final == 0) final = reference_length;

    if(aux[reference_length + 1] == '\0') return;
    else{
        acc++;
        beginning += reference_length;
        // BiggestSubstring(text, reference,reference_length, );
    }
}

int main(void){
    char str[101], sub[101];
    scanf("%s\n%s", str, sub);
    BiggestSubstring(str, sub, strlen(str), 0, 0, 0);
}


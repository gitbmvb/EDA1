#include <stdio.h>

void printChar(char * str){
    if(str[0] == '\0') return;
    printChar(str+1);
    printf("%c", str[0]);
}

int main(){
    char input[501];
    scanf("%s", input);
    printChar(input);
    printf("\n");
    return 0;
}
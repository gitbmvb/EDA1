#include <stdio.h>

void changeChar(char * str){
    if(str[0] == '\0') return;
    else if(str[0] == 'x') printf("y");
    else if(str[0] == 'X') printf("Y");
    else printf("%c", str[0]);
    changeChar(str+1);
}

int main(){
    char input[81];
    scanf("%s", input);
    changeChar(input);
    printf("\n");
    return 0;
}
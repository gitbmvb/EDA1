#include <stdio.h>

int pairs = 0;
void charCompare(char * str){
    if(str[2] == '\0') return;
    if(str[0] == str[2]) pairs++;
    charCompare(str+1);
}

int main(){
    char string[201];
    scanf("%s", string);
    charCompare(string);
    printf("%d\n", pairs);
    return 0;
}
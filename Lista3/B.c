#include <stdio.h>

void move_x(char * input){
    if(input[0] == '\0'){
        // printf("\b");
        return;
    }
    if(input[0] != 'x'){
        printf("%c", input[0]);
        move_x(&input[1]);
    } else{
        move_x(&input[1]);
        printf("%c", input[0]);
    }
}


int main(){
    char input[101];
    scanf("%s", input);
    move_x(input);
    printf("\n");
    return 0;
}
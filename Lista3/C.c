#include <stdio.h>
#include <string.h>

int sum = 0;
int level = 0;

int sumDigits(char * number){
    if(number[0] == '\0') return 0;
    int digit = number[0] - '0';
    return digit + sumDigits(&number[1]);
}

void greaterThan9(){
    level++;
    if(sum > 9){
        char aux[9001];
        sprintf(aux, "%d", sum);
        sum = sumDigits(aux);
        greaterThan9();
    }
}

int main(){
    char input[1000];
    scanf("%s", input);
    while(strcmp(input, "0") != 0){
        sum = 0;
        level = 0;
        sum = sumDigits(input);
        greaterThan9();
        
        if(sum == 9){
            printf("%s is a multiple of 9 and has 9-degree %d.\n", input, level);
        } else{
            printf("%s is not a multiple of 9.\n", input);
        }
        
        scanf("%s", input);
    }
    return 0;
}



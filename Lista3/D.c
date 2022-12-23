#include <stdio.h>
#include <string.h>

int sumAll(char * number){
    if(number[0] != '\0')
        return (number[0] - '0') + sumAll(&number[1]);
    else return 0;
}

int main(){
    char myNumber[13];
    scanf("%s", myNumber);
    printf("%d\n", sumAll(myNumber));
    return 0;
}
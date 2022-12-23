#include <stdio.h>

int main(){
    int a, b, c, answer, result = 0;
    scanf("%d %d %d", &a, &b, &c);
    scanf("%d", &answer);
    result = a + b + c;
    if(answer == result){
        printf("Acertou\n");
    } else{
        printf("Errou\n");
    }
    return 0;
}
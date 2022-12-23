#include <stdio.h>

int main(){
    int var, test, qtd = 0;
    do{
        test = scanf("%d", &var);
        qtd++;
    } while(test == 1);
    printf("%d\n", qtd - 1);
    return 0;
}
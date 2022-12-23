#include <stdio.h>

long int fibs[81] = {0};

long int fibonacci(int n){
    fibs[1] = 1;
    fibs[2] = 1;
    if(fibs[n] != 0) return fibs[n];
    fibs[n] = fibonacci(n-1) + fibonacci(n-2);
    return fibs[n];
}

int main(){
    for(int i = 1; i <= 80; i++){
        printf("fibonacci de %d = %ld\n", i, fibonacci(i));
    }
    return 0;
}
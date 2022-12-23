#include <stdio.h>
#include <stdlib.h>

int sum = 0;
void greaterThan(int * vet, int ref){
    if(vet[0] == 0) return;
    sum += vet[0];
    if(sum > ref){
        sum = 0;
        greaterThan(&vet[1], ref);
        printf("%d\n", vet[0]);
    } else greaterThan(&vet[1], ref);
}

int main(){
    int size = 1;
    int * numbers = (int*) malloc(size * 4), num, ref;
    scanf("\n%d", &num);
    do{
        numbers[size - 1] = num;
        size++;
        numbers = (int *) realloc(numbers, size * 4);
        scanf("\n%d", &num);
    } while(num != 0);

    scanf("\n%d", &ref);
    greaterThan(numbers, ref);
    free(numbers);
    return 0;
}
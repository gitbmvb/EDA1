#include <stdio.h>
#include <stdlib.h>

int sum = 0;
void MoreThanLimit(int * v, int limit, int length, int acc){
    if(acc > length) return;
    if(sum + v[0] > limit){
        sum = 0;
        MoreThanLimit(&v[1], limit, length, acc + 1);
        printf("%d\n", v[0]);
    } else{
        sum += v[0];
        MoreThanLimit(&v[1], limit, length, acc + 1);
    }

}


int main(void){
    int*  v = malloc(0), num, len = 0, limit;
    scanf("%d", &num);
    while(num != 0){
        len++;
        v = realloc(v, 4 * len);
        *(v + len-1) = num;
        scanf("\n%d", &num);
    }
    scanf("\n%d", &limit);
    MoreThanLimit(v, limit, len - 1, 0);
    free(v);
}
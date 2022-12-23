typedef int Item;
#include <stdio.h>
#include <stdlib.h>
#define key(A) (A)
#define less(A, B) (key(A) < key(B))
#define exch(A, B) {Item temp = A; A = B; B = temp;}

void bubblesort_sentinel(Item * v, int l, int r){
    int sentinel;
    for(int i = l; i < r; i++){
        for(int j = l; j < r; j++){
            if(less(v[j+1], v[j])){
                exch(v[j+1], v[j]);
                sentinel = 1;
            }
        }
        if(!sentinel) break;
    }
}

int main(void){
    int len = 0, * nums = malloc(len), num;
    while(scanf("%d", &num) == 1){
        nums = realloc(nums, sizeof(int) * ++len);
        nums[len - 1] = num;
    }
    bubblesort_sentinel(nums, 0, len - 1);
    for(int i = 0; i <= len -1; i++){
        printf("%d", nums[i]);
        if(i + 1 < len) printf(" ");
    }
}
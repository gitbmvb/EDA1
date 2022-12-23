typedef int Item;
#define Key(A) (A)
#define less(A, B) (Key(A) < Key(B))
#define exch(A, B) {Item temp = A; A = B; B = temp;}
#include <stdio.h>
#include <stdlib.h>

void selectionsort(Item * v, int l, int r){
    if(l >= r) return;
    int min = l;
    for(int i = l + 1; i <= r; i++){
        if(less(v[i], v[min])) min = i;
    }
    exch(v[l], v[min]);
    selectionsort(v, l + 1, r);
}

int main(void){
    int len = 0;
    Item num, * nums = malloc(sizeof(Item) * len);
    while(scanf("%d", &num) == 1){
        nums = realloc(nums, sizeof(Item) * ++len);
        nums[len-1] = num;
    }
    selectionsort(nums, 0, len - 1);
    for(int i = 0; i < len; i++){
        printf("%d", nums[i]);
        if(i+1 < len) printf(" ");
        else printf("\n");
    }
    free(nums);
}


#include <stdio.h>
#include <stdlib.h>
typedef int Item;
#define Key(A) (A)
#define less(A, B) (Key(A) < Key(B))
#define exch(A, B) {Item temp = A; A = B; B = temp;}
#define cmpexch(A, B) {if(less(A, B)) exch(A, B)};

void insertionsort(Item * v, int l, int r){
    for(int i = r; i > l; i--) cmpexch(v[i], v[i- 1]);
    for(int i = l + 2; i <= r; i++){
        Item temp = v[i];
        int j = i;
        while(less(temp, v[j - 1])){
            v[j] = v[j - 1];
            j--;
        }
        v[j] = temp;
    }
}

int main(void){
    int num, len = 0;
    Item *nums = malloc(sizeof(Item) * len);
    while(scanf("%d", &num) == 1){
        nums = realloc(nums, sizeof(Item) * ++len);
        nums[len - 1] = num;
    }
    insertionsort(nums, 0, len - 1);
    for(int i = 0; i < len; i++){
        printf("%d", nums[i]);
        if(i + 1 < len) printf(" ");
        else printf("\n");
    }
}
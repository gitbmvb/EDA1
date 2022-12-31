#include <stdio.h>
#include <stdlib.h>
typedef int Item;

void merge(Item * v, int l, int m, int r){
    Item * aux = malloc(sizeof(Item) * (r - l + 1));
    int i_left = l, i_right = m + 1, len = 0;
    while(i_left <= m && i_right <= r){
        if(v[i_left] <= v[i_right]) aux[len++] = v[i_left++];
        else aux[len++] = v[i_right++];
    }
    while(i_left <= m) aux[len++] = v[i_left++];
    while(i_right <= r) aux[len++] = v[i_right++];
    len = 0;
    for(int i = l; i <= r; i++) v[i] = aux[len++];
    free(aux);
}

void mergesort(Item * v, int l, int r){
    if(l >= r) return;
    int middle = (l + r)/2;
    mergesort(v, l, middle);
    mergesort(v, middle + 1, r);
    merge(v, l, middle, r);
}

int main(){
    int num, len = 0, * nums = malloc(0);
    while(scanf("%d", &num) == 1){
        nums = realloc(nums, sizeof(Item) * ++len);
        nums[len - 1] = num;
    }
    mergesort(nums, 0, len - 1);
    for(int i = 0; i < len; i++){
        printf("%d", nums[i]);
        if(i + 1 < len) printf(" ");
        else printf("\n");
    }
    free(nums);
    return 0;
}
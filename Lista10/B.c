#include <stdio.h>
#include <stdlib.h>
typedef int Item;
#define lesseq(A, B) (A < B || A == B)

void bruno(Item * v, int l, int m, int r){
    Item * aux = malloc(sizeof(Item) * (r - l + 1));
    int il = l, ir = m + 1, idx = 0;
    while(il <= m && ir <= r){
        if(lesseq(v[il], v[ir])) aux[idx++] = v[il++];
        else aux[idx++] = v[ir++];       
    }
    while(il <= m) aux[idx++] = v[il++];
    while(ir <= r) aux[idx++] = v[ir++];
    idx = 0;
    for(int i = l; i <= r; i++) v[i] = aux[idx++];
}

void mergesort(Item * v, int l, int r){
    if(l >= r) return;
    int middle = (r + l)/2;
    mergesort(v, l, middle);
    mergesort(v, middle + 1, r);
    bruno(v, l, middle, r);
}

int main(void){
    int qtd;
    scanf("%d", &qtd);
    int numbers[qtd];
    for(int i = 0; i < qtd; i++) scanf("%d", &numbers[i]);
    mergesort(numbers, 0, qtd - 1);
    for(int i = 0; i < qtd; i++){
        printf("%d ", numbers[i]);
        if(i + 1 < qtd) printf(" ");
        else printf("\n");
    }
    
}
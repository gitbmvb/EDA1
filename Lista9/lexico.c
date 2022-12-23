#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
typedef char* Item;
#define lesseq(A, B) (A < B || A == B)

void merge(Item * v, int l, int m, int r){
    Item * aux = malloc(sizeof(Item) * (r - l + 1));
    int il = l, ir = m + 1, idx = 0;
    while(il <= m && ir <= r){
        if(strcmp(v[il], v[ir]) <= 0)
            aux[idx++] = v[il++];
        else
            aux[idx++] = v[ir++];       
    }
    while(il <= m) aux[idx++] = v[il++];
    while(ir <= r) aux[idx++] = v[ir++];
    idx = 0;
    for(int i = l; i <= r; i++)
        v[i] = aux[idx++];
    free(aux);
}

void mergesort(Item * v, int l, int r){
    if(l >= r) return;
    int middle = (r + l)/2;
    mergesort(v, l, middle);
    mergesort(v, middle + 1, r);
    merge(v, l, middle, r);
}

int main(void){
    int qtd;
    scanf("%d", &qtd);
    Item* words = malloc(sizeof(Item) * qtd);
    for(int i = 0; i < qtd; i++){
        words[i] = malloc(sizeof(Item) * 15);
        scanf("%s", words[i]);
    }
    printf("\nArray:\n");
    for(int i = 0; i < qtd; i++) printf("%s\n", words[i]);
    mergesort(words, 0, qtd - 1);
    printf("============\nSortedArray:\n");
    for(int i = 0; i < qtd; i++) printf("%s\n", words[i]);
}
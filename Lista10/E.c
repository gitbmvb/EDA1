#include <stdio.h>
#include <stdlib.h>
typedef int Item;
#define lesseq(A, B) (A < B || A == B)

void merge(Item * v, int l, int m, int r){
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
    merge(v, l, middle, r);
}

int binary_search(Item * v, int l, int r, Item aim){
    if(l > r) return -1;
    int middle = (l + r)/2;
    if(v[middle] == aim) return middle;
    else if(aim < v[middle]) return binary_search(v, l, middle - 1, aim);
    else return binary_search(v, middle + 1, r, aim);
}

int main(void){
    int l, obj;
    scanf("%d", &l);
    Item * fbdd = malloc(sizeof(Item) * l);
    for(int i = 0; i < l; i++) scanf("%d", &fbdd[i]);
    mergesort(fbdd, 0, l - 1);
    while(scanf("%d", &obj) == 1) printf(binary_search(fbdd, 0, l - 1, obj) > -1 ? "sim\n":"nao\n");
}
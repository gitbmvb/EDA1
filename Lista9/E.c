#include <stdio.h>
#include <stdlib.h>
#define less(A, B) (A < B)
#define eq(A, B) (A == B)
#define lesseq(A, B) (A <= B)
struct obj{
    int code;
    char command[15];
};
typedef struct obj Item;

int binarysearch(Item * v, int l, int r, int aim){
    if(l > r) return -1;
    int middle = (r + l)/2;
    if(eq(v[middle].code, aim)) return middle;
    else if(less(aim, v[middle].code)) return binarysearch(v, l, middle - 1, aim);
    else return binarysearch(v, middle + 1, r, aim);
}

void merge(Item *v, int l, int m, int r){
    Item * aux = malloc(sizeof(Item) * (r -l + 1));
    int ileft = l, iright = m + 1, len = 0;
    while(lesseq(ileft, m) && lesseq(iright, r)){
        if(less(v[ileft].code, v[iright].code)) aux[len++] = v[ileft++];
        else aux[len++] = v[iright++];
    }
    while(lesseq(ileft, m)) aux[len++] = v[ileft++];
    while(lesseq(iright, r)) aux[len++] = v[iright++];
    len = 0;
    for(int i = l; i <= r; i++) v[i] = aux[len++];
    free(aux);
}
void mergesort(Item * v, int l, int r){
    if (l == r) return;
    int middle = (l + r)/2;
    mergesort(v, l, middle);
    mergesort(v, middle + 1, r);
    merge(v, l, middle, r);
}

int main(void){
    int qtd, search;
    scanf("%d", &qtd);
    Item * items = malloc(sizeof(Item) * qtd);
    for(int i = 0; i < qtd; i++) scanf("%d %s", &items[i].code, items[i].command);
    mergesort(items, 0, qtd -1);
    while(scanf("%d", &search) == 1){
        int index = binarysearch(items, 0, qtd - 1, search); 
        if(index > -1) printf("%s\n", items[index].command);
        else printf("undefined\n");
    }
}
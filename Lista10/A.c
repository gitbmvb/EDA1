#include <stdlib.h>
#include <stdio.h>
typedef int Item;
#define lesseq(A, B) (A <= B)

void merge2(Item * v, Item * v1, Item *v2, int l1, int l2, int r1, int r2){
    Item * aux = malloc(sizeof(Item) * (r1 + r2 - l1 - l2 + 2));
    int ileft = l1, iright = l2, len = 0;
    while(ileft <= r1 && iright <= r2){
        if(lesseq(v1[ileft], v2[iright])) aux[len++] = v1[ileft++];
        else aux[len++] = v2[iright++];
    }
    while(ileft <= r1) aux[len++] = v1[ileft++];
    while(iright <= r2) aux[len++] = v2[iright++];
    len = 0;
    for(int i = 0; i < (r1 + r2 - l1 - l2 + 2); i++) v[i] = aux[len++];
}

int main(void){
    int len = 0, n;
    Item * vetorzao = malloc(sizeof(Item) * len);
    for(int i = 0; i < 2; i++){
        scanf("%d", &n);
        Item * temp = malloc(sizeof(Item) * n);
        for(int j = 0; j < n; j++){
            scanf("%d", &temp[j]);
        }
        len += n;
        vetorzao = realloc(vetorzao, sizeof(Item) * len);
        merge2(vetorzao, vetorzao, temp, 0, 0, len -1, n - 1);
        free(temp);
    }
    for(int i = 0; i < len; i++) printf("%d ", vetorzao[i]);
    printf("\n");
}
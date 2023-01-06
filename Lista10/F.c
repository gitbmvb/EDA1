#include <stdio.h>
#include <stdlib.h>
typedef int Item;

Item * merge2(Item * v1, Item * v2, int l1, int l2, int r1, int r2){
    Item * aux = malloc(sizeof(Item) * (r2 + r1 - l2 -l1 + 2));
    int i_v1 = l1, i_v2 = l2, i_aux = 0;
    while(i_v1 <= r1 && i_v2 <= r2){
        if(v1[i_v1] <= v2[i_v2]) aux[i_aux++] = v1[i_v1++];
        else aux[i_aux++] = v2[i_v2++];
    }
    while(i_v1 <= r1) aux[i_aux++] = v1[i_v1++];
    while(i_v2 <= r2) aux[i_aux++] = v2[i_v2++];
    return aux;
}

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

Item * unique(Item *v, int * size){
    int len = 1, temp_size = *size;
    Item * temp = malloc(sizeof(Item) * len);
    temp[0] = v[0];
    for(int i = 1; i < *size; i++){
        if(v[i] == v[i-1]) temp_size--;
        else{
            temp = realloc(temp, sizeof(Item) * ++len);
            temp[len - 1] = v[i];
        }
    }
    *size = temp_size;
    return temp;
}

void even_length(Item * v, int * size){
    if(*size%2!=0){
        v = realloc(v, sizeof(Item) * ++(*size));
        v[*size - 1] = 1000000000;
    }
}

Item * generate_nmur(Item * v, Item * ref, int size){
    Item * temp = malloc(sizeof(Item) * size);
    for(int i = 0; i < size; i++) temp[i] = ref[2*i] + ref[2*i + 1];
    return temp;
}

int main(void){
    int N, resultN;
    scanf("%d", &N);
    Item * elements = malloc(sizeof(Item) * N);
    for(int i = 0; i < N; i++) scanf("%d", &elements[i]);
    mergesort(elements, 0, N - 1);
    elements = unique(elements, &N);
    even_length(elements, &N);
    Item * nmur = generate_nmur(nmur, elements, N/2);
    resultN = N + N/2;
    Item * result = malloc(sizeof(Item) * resultN);
    result = merge2(elements, nmur, 0, 0, N - 1, N/2 - 1);
    result = unique(result, &resultN);
    for(int i = 0; i < resultN; i += 4) printf("%d\n", result[i]);
    printf("Elementos: %d\n", resultN);
}
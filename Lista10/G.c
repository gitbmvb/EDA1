#include <stdio.h>
#include <stdlib.h>
#include <string.h>
struct obj{
    int i, p;
    char c;
};

typedef struct obj Item;

void merge(Item * v, int l, int m, int r){
    Item * aux = malloc(sizeof(Item) * (r - l + 1));
    int i_left = l, i_right = m + 1, len = 0;
    while(i_left <= m && i_right <= r){
        if(v[i_left].i < v[i_right].i){
            if(v[i_left].p < v[i_right].p) aux[len++] = v[i_left++];
            else aux[len++] = v[i_right++]; 
        }
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
    Item * results = malloc(0);
    char string[100001];
    scanf("%s", string);
    int acc = 1, length = 0, strlength = strlen(string), last_index = 0;
    char aux = string[0];
    
    for(int i = 1; i <= strlength; i++){
        if(string[i] == aux) acc++;
        else{
            results = realloc(results, sizeof(Item) * ++length);
            results[length-1].c = aux;
            results[length-1].p = last_index;
            results[length-1].i = acc;
            acc = 1;
            aux = string[i];
            last_index = i;
        }
    }
    mergesort(results, 0, length -1);
    for(int i = length -1 ; i >= 0; i--) printf("%d %c %d\n", results[i].i, results[i].c, results[i].p);
    return 0;
}
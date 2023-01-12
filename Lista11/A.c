#include <stdio.h>
typedef int Item;
#define lesseq(A, B) (A <= B)
#define less(A, B) (A < B)
#define exch(A, B) {Item temp = A; A = B; B = temp;}
#define cmpexch(A, B) if(less(A, B)) exch(A, B);

void insertionsort(Item * v, int l, int r){
    for(int i = r; i > l; i--) cmpexch(v[i], v[i-1]);
    for(int i = l + 2; i <= r; i++){
        int k = i;
        Item aux = v[k];
        while(less(aux, v[k -1])){
            v[k] = v[k -1];
            k--;
        }
        v[k] = aux;
    }
}

int partition(Item * v, int l, int r){
    Item c = v[r];
    int j = l;
    for(int k = l; k < r; k++){
        if(lesseq(v[k], c)){
            exch(v[j], v[k]);
            j++;
        }
    }
    exch(v[r], v[j]);
    return j;
}

void quicksort(Item * v, int l, int r){
    if(r - l <= 32) return;
    exch(v[(l + r)/2], v[r - 1]);
    cmpexch(v[r], v[r-1]);
    cmpexch(v[r-1], v[l]);
    cmpexch(v[r], v[r-1]);
    int j = partition(v, l + 1, r - 1);
    quicksort(v, l, j - 1);
    quicksort(v, j + 1, r);
}

void quicksortinsertion(Item *v, int l, int r){
    quicksort(v, l, r);
    insertionsort(v, l, r);
}

int main(void){
    int n;
    scanf("%d", &n);
    int elements[n];
    for(int i = 0; i < n; i++) scanf("%d", &elements[i]);
    quicksortinsertion(elements, 0, n - 1);
    for(int i = 0; i < n; i++) (i + 1 < n) ? printf("%d ", elements[i]) : printf("%d\n", elements[i]);
}
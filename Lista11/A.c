#include <stdio.h>
typedef int Item;
#define lesseq(A, B) (A <= B)
#define exch(A, B) {Item temp = A; A = B; B = temp;}

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
    if(l >= r) return;
    int j = partition(v, l, r);
    quicksort(v, l, j - 1);
    quicksort(v, j + 1, r);
}

int main(void){
    int n;
    scanf("%d", &n);
    int elements[n];
    for(int i = 0; i < n; i++) scanf("%d", &elements[i]);
    quicksort(elements, 0, n - 1);
    for(int i = 0; i < n; i++) (i + 1 < n) ? printf("%d ", elements[i]) : printf("%d\n", elements[i]);
}
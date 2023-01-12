#include <stdio.h>
#include <string.h>
struct word{ char port[81], jap[81];};
typedef struct word Item;
#define exch(A, B) {Item temp = A; A = B; B = temp;}

int binarysearch(Item *v, int l, int r, char * aim){
    if(l > r) return -1;
    int m = (l + r)/2;
    int compare = strcmp(v[m].jap, aim); 
    if(compare == 0) return m;
    else if(compare > 0) return binarysearch(v, l, m - 1, aim);
    else return binarysearch(v, m + 1, r, aim);
}

int partition(Item * v, int l, int r){
    Item c = v[r];
    int j = l;
    for(int k = l; k < r; k++){
        if(strcmp(c.jap, v[k].jap) <= 0){
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
    int T, M, N;
    scanf("%d", &T);
    for(int i = 0; i < T; i++){
        scanf("%d %d", &M, &N);
        Item words[M];
        for(int j = 0; j < M; j++) scanf("\n%[^\n] %[^\n]", words[j].jap, words[j].port);
        for(int j = 0; j < N; j++){
            char aux[81];
            scanf("\n%[^\n]", aux);
            int k = 0;
            while(k != '\n'){
               
            }
        }
    }

}
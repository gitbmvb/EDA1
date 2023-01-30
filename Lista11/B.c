#include <stdio.h>
#include <stdlib.h>
#include <string.h>
struct word { char japanese[80], portuguese[80];};
typedef struct word Word;
#define less(A, B) (A < B)
#define exch(A, B) {Word temp = A; A = B; B = temp;};

int binarysearch(Word * v, int l, int r, char * aim){
    if(l > r) return -1;
    int m = (l + r)/2;
    int compare = strcmp(aim, v[m].japanese); 
    if(compare == 0) return m;
    else if(compare < 0) return binarysearch(v, l, m - 1, aim);
    else return binarysearch(v, m + 1, r, aim);
}

int partition(Word * v, int l, int r){
    Word c = v[r];
    int j = l;
    for(int k = l; k < r; k++)
        if(strcmp(v[k].japanese, c.japanese) < 0){
            exch(v[k], v[j]);
            j++;
        }
    exch(v[j], v[r]);
    return j;
}

void quicksort(Word * v, int l, int r){
    if(l >= r) return;
    int j = partition(v, l, r);
    quicksort(v, l, j - 1);
    quicksort(v, j + 1, r);
}

int main(void){
    int T, M, N;
    scanf("%d", &T);
    for(int i = 0; i < T; i++){
        scanf("%d %d\n", &M, &N);
        // Word words[M];
        // for(int j = 0; j < M; j++){
        //     fgets(words[j].japanese, 80, stdin);
        //     fgets(words[j].portuguese, 80, stdin);
        // }
        // quicksort(words, 0, M - 1);
        for(int j =0; j < N; j++){
            char temp[80];
            while(scanf("%s ", temp) == 1){
                printf("%s ", temp);
                if(temp[strlen(temp) - 1] == '\n') break;
            }
            printf("\n");
        }
    }
}
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
struct candidate{int code, votes;};
typedef struct candidate Item;
#define exch(A, B) {Item temp = A; B = A; A = temp;}
#define lesseq(A, B) (B <= A)

int length_of(int x) {return (x/10 == 0) ? 1 : 1 + length_of(x/10);};

int binarysearch(Item * v, int l, int r, int aim){
    if(l > r) return -1;
    int m = (l + r)/2;
    if(v[m].code == aim) return m;
    else if(aim < v[m].code) return binarysearch(v, l, m - 1, aim);
    else return binarysearch(v, m + 1, r, aim);
}

void make_a_vote(Item ** jobs, int * votes, int * lenghts, int item){
    if(item < 0) votes[0]++;
    else{
        int item_len = length_of(item) - 2;
        int index_vote = binarysearch(jobs[item_len], 0, lenghts[item_len] - 1, item);
        if(index_vote < 0){
            lenghts[item_len]++;
            jobs[item_len] = realloc(jobs[item_len], sizeof(Item) * lenghts[item_len]);
            jobs[item_len][lenghts[item_len] - 1].code = item;
            jobs[item_len][lenghts[item_len] - 1].votes = 1;
        } else jobs[item_len][index_vote].votes++;
        votes[1]++;
    }
}

int partition(Item *v, int l, int r){
    Item c = v[r]; int j = l;
    for(int k = l; k < r; k++){
        if(lesseq(v[k].votes, c.votes)){
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
    int lengths[4] = {0, 0, 0, 0}, votes_IV[2] = {0, 0}, qtdSFE[4] = {1, 0, 0 ,0}, item;
    Item ** jobs = malloc(sizeof(Item*) * 4);
    for(int i = 0; i < 4; i++) jobs[i] = malloc(sizeof(Item) * lengths[i]);
    scanf("%d %d %d", &qtdSFE[1], &qtdSFE[2], &qtdSFE[3]);
    while(scanf("%d", &item) == 1) make_a_vote(jobs, votes_IV, lengths, item);
    printf("%d %d\n", votes_IV[1], votes_IV[0]);
    for(int i = 0; i < 4; i++){
        quicksort(jobs[i], 0, lengths[i] - 1);
        for(int j = 0; j < lengths[i]; j++){
            printf("code = %d, votes = %d\n", jobs[i][j].code, jobs[i][j].votes);
        }
        // for(int j = lengths[i] - 1; j >= qtdSFE[i]; j--) (lengths[i] - 1 >= qtdSFE[i]) ? printf("%d ", jobs[i][j].code) : printf("%d\n", jobs[i][j].code);
        // if(i + 1 < 4) printf("\n");
    }
}
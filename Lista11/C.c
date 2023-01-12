#include <stdio.h>
#include <stdlib.h>
#include <string.h>
struct candidate{int code, votes;};
typedef struct candidate Item;
#define exch(A, B) {Item temp; temp.code = A.code; temp.votes = A.votes; A.code = B.code; A.votes = B.votes; B.code = temp.code; B.votes = temp.votes;}
#define less(A, B) (A < B)
#define cmpexch(A, B) if(less(A, B)) exch(A, B)

int length_of(int x) {return (x/10 == 0) ? 1 : 1 + length_of(x/10);};

int binarysearch(Item * v, int l, int r, int aim){
    if(l > r) return -1;
    int m = (l + r)/2;
    if(v[m].code == aim) return m;
    else if(aim < v[m].code) return binarysearch(v, l, m - 1, aim);
    else return binarysearch(v, m + 1, r, aim);
}

int linearsearch(Item *v, int l, int r, int aim){
    if(l > r) return -1;
    if(v[l].code == aim) return l;
    else return linearsearch(v, l + 1, r, aim);
}

void insertionsort(Item * v, int l, int r){
    for(int i = r; i > l; i--){
        if(less(v[i].votes, v[i-1].votes)) exch(v[i], v[i-1]);
    }
    for(int i = l + 2; i <= r; i++){
        int k = i;
        Item aux = v[k];
        while(less(aux.votes, v[k - 1].votes)){
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
        if(less(c.votes, v[k].votes)){
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
    if(less(v[r].votes, v[r-1].votes)) exch(v[r], v[r-1]);
    if(less(v[r-1].votes, v[l].votes)) exch(v[r-1], v[l]);
    if(less(v[r].votes, v[r-1].votes)) exch(v[r], v[r-1]);;
    int j = partition(v, l + 1, r - 1);
    quicksort(v, l, j - 1);
    quicksort(v, j + 1, r);
}

void quicksortinsertion(Item *v, int l, int r){
    quicksort(v, l, r);
    insertionsort(v, l, r);
}

void make_a_vote(Item ** jobs, int * votes, int * lenghts, int item){
    if(item < 0) votes[0]++;
    else{
        int item_len = length_of(item) - 2;
        int index_vote = linearsearch(jobs[item_len], 0, lenghts[item_len] - 1, item);
        if(index_vote < 0){
            lenghts[item_len]++;
            jobs[item_len] = realloc(jobs[item_len], sizeof(Item) * lenghts[item_len]);
            jobs[item_len][lenghts[item_len] - 1].code = item;
            jobs[item_len][lenghts[item_len] - 1].votes = 1;
        } else jobs[item_len][index_vote].votes++;
        votes[1]++;
    }
}

void show_results(Item ** v, int * lens, int * qtds){
    for(int i = 0; i < 4; i++){
        quicksortinsertion(v[i], 0, lens[i] - 1);
        for(int j = lens[i] - 1; j >= lens[i] - qtds[i]; j--) (j - 1 >= lens[i] - qtds[i]) ? printf("%d ", v[i][j].code) : printf("%d\n", v[i][j].code);
    }
}

int main(void){
    int lengths[4] = {0, 0, 0, 0}, votes_IV[2] = {0, 0}, qtdPSFE[4] = {1, 0, 0 ,0}, item;
    Item ** jobs = malloc(sizeof(Item*) * 4);
    for(int i = 0; i < 4; i++) jobs[i] = malloc(sizeof(Item) * lengths[i]);
    scanf("%d %d %d", &qtdPSFE[1], &qtdPSFE[2], &qtdPSFE[3]);
    while(scanf("%d", &item) == 1) make_a_vote(jobs, votes_IV, lengths, item);
    printf("%d %d\n", votes_IV[1], votes_IV[0]);
    show_results(jobs, lengths, qtdPSFE);
}
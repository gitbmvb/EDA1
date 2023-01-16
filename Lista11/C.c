#include <stdio.h>
#include <stdlib.h>
struct candidate{int code, votes;};
typedef struct candidate Candidate;
#define exch(A, B) {Candidate temp; temp.code = A.code; temp.votes = A.votes; A.code = B.code; A.votes = B.votes; B.code = temp.code; B.votes = temp.votes;}
#define less(A, B) (A < B)
#define lesseq(A, B) (A <= B)
#define equals(A, B) (A == B)
#define cmpexch(A, B) if(less(A, B)) exch(A, B)
#define key(A) A.votes

int length_of(int x) { return (x/10 == 0) ? 1 : 1 + length_of(x/10);};

int binarysearch(Candidate * cands, int l, int r, int aim){
    if(l > r) return -1;
    int m = l + (r - l)/2;
    if(cands[m].code == aim) return m;
    else if(less(aim, cands[m].code)) return binarysearch(cands, l, m - 1, aim);
    else return binarysearch(cands, m + 1, r, aim);
}

int linearsearch(Candidate * cands, int l, int r, int aim){
    if(l > r) return -1;
    return (cands[l].code == aim) ? l : linearsearch(cands, l + 1, r, aim);
} 

void insertionsort(Candidate * cands, int l, int r){
    for(int i = r; i > l; i--){
        if(less(key(cands[i]), key(cands[i-1])) ||
        (equals(key(cands[i]), key(cands[i-1])) && less(cands[i].code, cands[i-1].code))) exch(cands[i], cands[i-1]);
    }
    for(int i = l + 2; i <= r; i++){
        int k = i;
        Candidate aux = cands[k];
        while(less(key(aux), key(cands[k - 1])) ||
        (equals(key(aux), key(cands[k - 1])) && less(aux.code, cands[k-1].code))){
            cands[k] = cands[k -1];
                k--;
        }
        cands[k] = aux;
    }
}

int partition(Candidate * cands, int l, int r){
    Candidate c = cands[r];
    int j = l;
    for(int k = l; k < r; k++){
        if(less(key(c), key(cands[k]))){
            exch(cands[j], cands[k]);
            j++;
        }
    }
    exch(cands[r], cands[j]);
    return j;
}

void quicksort(Candidate * cands, int l, int r){
    if(r - l <= 32) return;
    exch(cands[(l + r)/2], cands[r - 1]);
    if(less(key(cands[r]), key(cands[r-1]))) exch(cands[r], cands[r-1]);
    if(less(key(cands[r-1]), key(cands[l]))) exch(cands[r-1], cands[l]);
    if(less(key(cands[r]), key(cands[r-1]))) exch(cands[r], cands[r-1]);;
    int j = partition(cands, l + 1, r - 1);
    quicksort(cands, l, j - 1);
    quicksort(cands, j + 1, r);
}

void quicksortinsertion(Candidate * cands, int l, int r){
    quicksort(cands, l, r);
    insertionsort(cands, l, r);
}

void make_a_vote(Candidate ** cands, int * qtd, int * votes, int item){
    if(item < 0) votes[0]++;
    else{
        int itemlen = length_of(item) - 2, itemindex = linearsearch(cands[itemlen], 0, qtd[itemlen] - 1, item);
        if(itemindex < 0){
            cands[itemlen] = realloc(cands[itemlen], sizeof(Candidate) * ++qtd[itemlen]);
            cands[itemlen][qtd[itemlen] - 1].code = item;
            cands[itemlen][qtd[itemlen] - 1].votes = 1;
        } else cands[itemlen][itemindex].votes++;
        votes[1]++;
        if(itemlen == 0) votes[2]++;
    }
}

void show_results(Candidate ** cands, int * qtd, int * PSFE, int * votesIVP){
    for(int i = 0; i < 4; i++){
        quicksortinsertion(cands[i], 0, qtd[i] - 1);
        for(int j = qtd[i] - 1; j >= qtd[i] - PSFE[i]; j--){
            (i == 0 && key(cands[i][j]) * 100/votesIVP[2] < 51) ? printf("Segundo turno") : printf("%d", cands[i][j].code);
            (j - 1 >= qtd[i] - PSFE[i]) ? printf(" ") : printf("\n");
        }
    }
}

int main(){
    int PSFE[4] = {1, 0, 0, 0}, votesIVP[3] = {0, 0, 0}, qtd[4] = {0, 0, 0, 0}, item;
    Candidate ** cands = malloc(sizeof(Candidate*) * 4);
    for(int c = 0; c < 4; c++) cands[c] = malloc(sizeof(Candidate) * qtd[c]);
    scanf("%d %d %d", &PSFE[1], &PSFE[2], &PSFE[3]);
    while(scanf("%d", &item) == 1) make_a_vote(cands, qtd, votesIVP, item);
    printf("%d %d\n", votesIVP[1], votesIVP[0]);
    show_results(cands, qtd, PSFE, votesIVP);
}
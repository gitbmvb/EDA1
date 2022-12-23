#include <stdio.h>
struct obj{
    int value;
    int relative_position;
};
typedef struct obj Item;
#define less(A, B) (A < B)
#define exch(A, B) {Item temp = A; A = B; B = temp;}

void insertionsort(Item * v, int l, int r){
    for(int i = r; i > l; i--){
        if(less(v[i].value, v[i - 1].value)) exch(v[i], v[i-1]);
    }
    for(int i = l + 2; i <= r; i++){
        Item temp = v[i];
        int aux = i;
        while(less(temp.value, v[aux - 1].value)){
            v[aux] = v[aux - 1];
            aux--;
        }
        v[aux] = temp;
    }
}

int binarysearch(Item * v, int l, int r, int aim){
    if(l > r) return -1;
    int middle = (r + l)/2;
    if(v[middle].value == aim)
        return v[middle].relative_position;
    else if(less(aim, v[middle].value)) return binarysearch(v, l, middle -1, aim);
    else return binarysearch(v, middle + 1, r, aim);
}

int main(){
    int N, M;
    scanf("%d %d", &N, &M);
    struct obj objs[N];
    for(int i = 0; i < N; i++){
        scanf("%d", &objs[i].value);
        objs[i].relative_position = i;
    }
    insertionsort(objs, 0, N - 1);
    for(int i = 0; i < M; i++){
        int aim;
        scanf("%d", &aim);
        printf("%d\n", binarysearch(objs, 0, N - 1, aim));
    }
    return 0;
}
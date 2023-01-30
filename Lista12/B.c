#include <stdio.h>
#include <stdlib.h>
typedef struct boot { int size; char side;} Item;
typedef struct queue { Item * v; int begin, end, size, used; } Queue;

int initialize(Queue * q , int s){
    q->v = malloc(sizeof(Item) * s);
    if(q->v == NULL) return 0;
    q->begin = 0; q->end = 0; q->size = s; q->used = 0;
    return 1;
}

int enqueue(Queue * q, Item e){
    if(q->used == q->size) return 0;
    q->v[q->end].size = e.size; q->v[q->end].side = e.side;
    q->used++;
    q->end = (q->end + 1) % q->size;
    return 1;
}

Item first_in(Queue * q){ return q->v[q->begin];}

void dequeue(Queue * q){
    q->used--;
    q->begin = (q->begin + 1) % q->size;
}

int main(void){
    int N, amount = 0, size, flag = 1;
    char side;
    Queue boots;
    while(scanf("%d", &N) == 1){
        initialize(&boots, N);
        for(int i = 0; i < N; i++){
            flag = 0;
            scanf("%d %c", &size, &side);
            int aux = boots.used;
            for(int j = 0; j < aux; j++){
                Item first = first_in(&boots);
                if(size == first.size && ((side == 'D' && first.side == 'E') || (side == 'E' && first.side == 'D'))){
                    dequeue(&boots);
                    amount++;
                    flag = 1;
                    break;
                }
                dequeue(&boots);
                enqueue(&boots, first);
            }
            if(!flag) enqueue(&boots, (Item){size, side});
        }
        printf("%d\n", amount);
        amount = 0;
    }
}

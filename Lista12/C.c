#include <stdio.h>
#include <stdlib.h>

typedef int Item;
typedef struct queue { Item * v; int begin, end, size, used;} Queue;

int initialize(Queue * q, int s){
    q->v = malloc(sizeof(Item) * s);
    if(q->v == NULL) return 0;
    q->begin = 0; q->end = 0; q->size = s; q->used = 0;
    return 1;
}

int enqueue(Queue * q, Item e){
    if(q->used == q->size) return 0;
    q->v[q->end] = e;
    q->end = (q->end + 1) % q->size;
    q->used++;
    return 1;
}

Item dequeue(Queue * q){
    q->used--;
    Item temp = q->v[q->begin];
    q->begin = (q->begin + 1) % q->size;
    return temp;
}

void finish(Queue * q){
    free(q->v);
    q->begin = 0;
    q->end = 0;
    q->size = 0;
    q->used = 0;
}

int main(void){
    int p, r, aux, command, amount, action, test = 1;
    Queue people;
    scanf("%d %d", &p, &r);
    while(p != 0 && r != 0){
        initialize(&people, p);
        for(int i = 0; i < p; i++){
            scanf("%d", &aux);
            enqueue(&people, aux);
        }
        for(int i = 0; i < r; i++){
            scanf("%d %d", &amount, &command);
            for(int j = 0; j < amount; j++){
                scanf("%d", &action);
                (action == command) ? enqueue(&people, dequeue(&people)) : dequeue(&people);
            }
        }
        printf("Teste %d\n%d\n", test++, dequeue(&people));
        finish(&people);
        scanf("%d %d", &p, &r);
    }
}
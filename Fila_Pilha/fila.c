#include <stdio.h>
#include <stdlib.h>

typedef char Item;
typedef struct Queue { Item * v; int begin, end, size, used;} Queue;

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
    Item temp = q->v[q->begin];
    q->used--;
    q->begin = (q->begin + 1) % q->size;
    return temp;
}

int is_empty(Queue * q){
    return q->used == 0;
}

Item first_in(Queue * q){
    return q->v[q->begin];
}

void print_backwards(Queue * q){
    if(is_empty(q)) return;
    Item temp = dequeue(q);
    print_backwards(q);
    printf("%d\n", temp);
}

void print_vector(Queue * q){
    for(int i = 0; i < q->used; i++){
        Item temp = dequeue(q);
        printf("%d\n", temp);
        enqueue(q, temp);
    }
}

int main(void){
    Queue myq;
    initialize(&myq, 10);
    
    enqueue(&myq, 'a');
    enqueue(&myq, 'b');
    enqueue(&myq, 'c');
    dequeue(&myq);
    enqueue(&myq, 'e');
    enqueue(&myq, first_in(&myq));
    enqueue(&myq, dequeue(&myq));
    dequeue(&myq);
    enqueue(&myq, enqueue(&myq, enqueue(&myq, first_in(&myq))) + 'd') ;
    dequeue(&myq);
    enqueue(&myq, dequeue(&myq) + dequeue(&myq));
    
    // enqueue(&myq, 10);
    // enqueue(&myq, 20);
    // enqueue(&myq, -3);
    // enqueue(&myq, -15);
    // enqueue(&myq, 20);
    // enqueue(&myq, 50);
    // print_backwards(&myq);
}
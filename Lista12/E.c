#include <stdio.h>
#include <stdlib.h>
typedef int Item;
typedef struct cell { Item e; struct cell * next; } Cell;
typedef struct head { Cell * begin, *end; Item count;} Head;
void initialize(Head * h){ h->begin = NULL; h->end = NULL; h->count = 0;}

void insert(Head * h, Item e){
    Cell * new = malloc(sizeof(Cell));
    new->e = e; new->next = NULL;
    h->count++;  
    if(h->begin == NULL) {h->begin = new; h->end = new; return;}
    h->end->next = new; h->end = new;
}

Item pop(Head * h){
    Cell * rm = h->begin;
    Item aux = rm->e;
    h->begin = rm->next;
    h->count--;
    free(rm);
    return aux;
}

int main(void){
    int n;
    Head cards;
    initialize(&cards);
    scanf("%d", &n);
    for(int i = 1; i <= n; i++) insert(&cards, i);
    printf("Cartas descartadas:");
    while(cards.count >= 2){
        (cards.count - 1 >= 2) ? printf(" %d,", pop(&cards)) : printf(" %d\n", pop(&cards));
        insert(&cards, pop(&cards));
    }
    printf("Carta restante: %d\n", cards.end->e);
}
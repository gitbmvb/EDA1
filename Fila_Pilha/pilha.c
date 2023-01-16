#include <stdio.h>
#include <stdlib.h>
typedef int Item;
struct pilha {Item * v; int topo, size;};
typedef struct pilha Pilha;

int inicializa(Pilha * p, int s){
    p->v = malloc(sizeof(Item) * s);
    if(p->v == NULL) return 0;
    p->topo = 0;
    p->size = s;
    return 1;
}

int empilha(Pilha * p, Item e){
    if(p->size == p->topo) return 0;
    p->v[p->topo++] = e;
    return 1;
}

void desempilha(Pilha * p){
    p->topo--;
}

int esta_vazia(Pilha * p){
    return p->topo == 0;
}

Item topo(Pilha * p){
    return p->v[p->topo];
}
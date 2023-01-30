#include <stdio.h>
#include <stdlib.h>
typedef char Item;
typedef struct stack { Item * v; int size, top;} Stack;

int init(Stack * s, int size){
    s->v = malloc(sizeof(Item) * size);
    if(s->v == NULL) return 0;
    s->top = 0; s->size = size;
    return 1;
}

int insert(Stack * s, Item e){
    if(s->size == s->top) return 0;
    s->v[s->top++] = e;
    return 1;
}

void pop(Stack * s){ if(s->top == 0) return; s->top--; }
Item last_in(Stack * s){ return s->v[s->top - 1]; }
int is_empty(Stack * s){ return s->top == 0; }

int main(void){
    int T;
    scanf("%d", &T);
    for(int i = 0; i < T; i++){
        Stack chars;
        int j = -1, flag = 1;
        char phrase[100000];
        init(&chars, 100000);
        scanf("%s", phrase);
        while(phrase[++j] != '\0'){
            if(phrase[j] == '{' || phrase[j] == '[' || phrase[j] == '(') insert(&chars, phrase[j]);
            else if(last_in(&chars) == '{' && phrase[j] == '}' || last_in(&chars) == '[' && phrase[j] == ']' || last_in(&chars) == '(' && phrase[j] == ')') pop(&chars);
            else flag = 0;
        }
        (flag && is_empty(&chars)) ? printf("S\n") : printf("N\n");
        free(chars.v);
    }
}
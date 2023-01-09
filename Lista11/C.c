#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct candidato{
    int codigo, votos;
};

typedef struct candidato Item;

int tamanho(int x){
    if(x/10 == 0) return 1;
    else return 1 + tamanho(x/10);
}

int length_of(int x){
    if(x/10 == 0) return 1;
    else return 1 + tamanho(x/10);
}

void make_a_vote(){

}

int binarysearch(Item * v, int l, int r, int aim){
    if(l > r) return -1;
    int m = (l + r)/2;
    if(v[m].codigo == aim) return m;
    else if(aim < v[m].codigo) return binarysearch(v, l, m - 1, aim);
    else return binarysearch(v, m + 1, r, aim);
}


int main(void){
    int lengths[4] = {0, 0, 0, 0}, votes_invalid_valid[2] = {0, 0}, S, F, E;
    Item ** votes = malloc(sizeof(Item*) * 4);
    
    int len_P = 0, len_S = 0, len_F = 0, len_E = 0, item, votos_validos = 0, votos_invalidos = 0;
    scanf("%d %d %d", &S, &F, &E);
    Item
    * presidentes = malloc(sizeof(Item) * len_P),
    * senadores = malloc(sizeof(Item) * len_S),
    * federais = malloc(sizeof(Item) * len_F),
    * estaduais = malloc(sizeof(Item) * len_E);
    while(scanf("%d", &item) == 1){
        int tam = tamanho(item);
        if(tam == 2 && tam > 0){
            votos_validos++;
            int teste_codigo = binarysearch(presidentes, 0, len_P - 1, item);
            if(teste_codigo < 0){
                len_P++;
                presidentes = realloc(presidentes, sizeof(Item) * len_P);
                presidentes[len_P - 1].codigo = item;
                presidentes[len_P - 1]. votos = 1;
            } else{
                presidentes[teste_codigo].votos++;
            }
        } else if(tam == 3 && tam > 0){
            votos_validos++;
            int teste_codigo = binarysearch(senadores, 0, len_P - 1, item);
            if(teste_codigo < 0){
                len_S++;
                senadores = realloc(senadores, sizeof(Item) * len_S);
                senadores[len_S - 1].codigo = item;
                senadores[len_S - 1]. votos = 1;
            } else{
                senadores[teste_codigo].votos++;
            }
        } else if(tam == 4 && tam > 0){
            votos_validos++;
            int teste_codigo = binarysearch(federais, 0, len_P - 1, item);
            if(teste_codigo < 0){
                len_F++;
                federais = realloc(federais, sizeof(Item) * len_F);
                federais[len_F - 1].codigo = item;
                federais[len_F - 1]. votos = 1;
            } else{
                federais[teste_codigo].votos++;
            }
        } else if(tam == 5 && tam > 0){
            votos_validos++;
            int teste_codigo = binarysearch(estaduais, 0, len_P - 1, item);
            if(teste_codigo < 0){
                len_E++;
                estaduais = realloc(estaduais, sizeof(Item) * len_E);
                estaduais[len_E - 1].codigo = item;
                estaduais[len_E - 1]. votos = 1;
            } else{
                estaduais[teste_codigo].votos++;
            }
        } else{
            votos_invalidos++;
        }
    }
    //

}
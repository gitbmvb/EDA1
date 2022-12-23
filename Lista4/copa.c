#include <stdio.h>

int main(){
    int t, n, empates;
    scanf("\n%d %d", &t, &n);
    while(t != 0){
        empates = 0;
        for(int i = 0; i < t; i++){
            int aux = 0;
            char nome[11];
            scanf("\n%s %d", nome, &aux);
            if(aux >= 3){
                empates += aux%3;
            } else{
                empates += aux;
            }
        }
        empates /= 2;
        printf("%d\n", empates);
        scanf("\n%d %d", &t, &n);
    }
    return 0;
}
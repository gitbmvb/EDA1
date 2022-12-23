#include <stdio.h>
#include <stdlib.h>

int main(){
    int linhas;
    scanf("%d\n", &linhas);
    int ultimaColuna[linhas];

    char grid[linhas][1001];
    for(int l = 0; l < linhas; l++){
        int aux = 0;
        char letter = getchar();
        while(letter != '\n'){
            grid[l][aux] = letter;
            aux++;
            letter = getchar();
        }
        ultimaColuna[l] = aux - 1;
    }
    for(int i = 0; i < linhas; i++){
        // printf("ultimaColunas[%d] = %d\n", i, ultimaColuna[i]);
    }

    int cL, cC;
    scanf("%d %d\n", &cL, &cC);
    cL -= 1;
    cC -= 1;
    // printf("cL = %d\n", cL);
    // printf("cC = %d\n", cC);
    // printf("ultimaColuna[%d] = %d\n", cL, ultimaColuna[cL]);
    // if(cC > ultimaColuna[cL]){
    //     printf("simmm\n");
    //     cC = ultimaColuna[cL];
    // }

    int temp = cC;
    char inputLetter;
    while((scanf("\n%c", &inputLetter)) != EOF){
        //Descer
        if((inputLetter == 'j') && (cL < linhas - 1)){
            if(ultimaColuna[cL + 1] <= cC){
                // printf("aaaa\n");
                temp = ultimaColuna[cL + 1];
                // printf("temp = %d\n", temp);
            } else{
                temp = cC;
            }
            cL += 1;    
        }
        //Subir
        else if((inputLetter == 'k') && (cL > 0)){
            if(ultimaColuna[cL - 1] < cC){
                temp = ultimaColuna[cL - 1];
            } else{
                temp = cC;
            }
            cL -= 1;
        }
        printf("%d %d %c\n", cL + 1, temp + 1, grid[cL][temp]);
    }
    
    return 0;
}
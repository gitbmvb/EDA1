#include <stdio.h>
#include <stdlib.h>

void borda(){
    for(int i = 0; i < 11; i++){
        printf("~");
    }
    printf("\n");
}

int main(void){
    int linhas, galhos;
    scanf("%d\n%d", &linhas, &galhos);
    char grid[linhas][11], lenhador;

    //Limpando cada caractere da matriz
    for(int i = 0; i < linhas; i++){
        for(int j = 0; j < 11; j++){
            grid[i][j] = ' ';
        }
    }

    //Definindo a posição dos galhos
    for(int i = 0; i < galhos; i++){
        char posicao;
        int altura;
        scanf("\n%c %d", &posicao, &altura);
        if(posicao == 'D'){
            grid[linhas - altura][7] = '-'; grid[linhas - altura][8] = '-'; grid[linhas - altura][9] = '-';
        }
        else if(posicao == 'E'){
            grid[linhas - altura][1] = '-'; grid[linhas - altura][2] = '-'; grid[linhas - altura][3] = '-';
        }
    }

    //Definindo a posição do lenhador
    scanf("\n%c\n", &lenhador);
    if(lenhador == 'E'){
        grid[linhas - 1][2] = 'L'; grid[linhas - 2][2] = 'L';
    } else if(lenhador == 'D'){
        grid[linhas - 1][8] = 'L'; grid[linhas - 2][8] = 'L';
    }

    //Definindo a posição do tronco
    for(int i = 0; i < linhas; i++){
        grid[i][4] = '|'; grid[i][5] = '|'; grid[i][6] = '|';
    }
    
    //Imprime o estado inicial
    borda();
    for(int i = linhas - 5; i < linhas; i++){
        for(int j = 0; j < 11; j++){
            printf("%c", grid[i][j]);
        }
        printf("\n");
    }
    borda();

    //Testa cada letra do comando
    int batidas = 0, tronco = linhas, comandosQtd = 0;
    char comando = getchar();
    while(comando != '\n' && comando != EOF && comandosQtd <= 2000){
        if(comando == 'T'){
            if((grid[linhas - 1][2] == 'L')){
                if((grid[linhas - 1][8] != '-') && (grid[linhas - 2][8] != '-')){
                        grid[linhas - 1][2] = ' '; grid[linhas - 2][2] = ' ';
                        grid[linhas - 1][8] = 'L'; grid[linhas - 2][8] = 'L';
                        lenhador = 'D';
                } else{
                    printf("**beep**\n");
                    goto Proximo;
                }
            }
            else if((grid[linhas - 1][8] == 'L')){
                if((grid[linhas - 1][2] != '-') && (grid[linhas - 2][2] != '-')){
                        grid[linhas - 1][8] = ' '; grid[linhas - 2][8] = ' ';
                        grid[linhas - 1][2] = 'L'; grid[linhas - 2][2] = 'L';
                        lenhador = 'E';
                } else{
                    printf("**beep**\n");
                    goto Proximo;
                }
            }
            if(batidas > 0){
                batidas --;
            }
        }
        else if(comando == 'B'){
            if(tronco == 0){
                break;
            }
            if(batidas < 1){
                if(lenhador == 'E'){
                    grid[linhas - 1][4] = '>';
                } else if(lenhador == 'D'){
                    grid[linhas - 1][6] = '<';
                }
                batidas++;
            } else{
                //Baixa um nível cada linha
                for(int i = linhas-1 ; i > 0; i--){
                    for(int j = 0; j < 11; j++){
                        grid[i][j] = grid[i-1][j];
                        grid[i-1][j] = ' '; 
                    }
                }

                //Testa se o galho atingiu o lenhador
                if((grid[linhas - 1][2] == 'L') && (grid[linhas - 2][2] != '-')){
                    grid[linhas - 2][2] = 'L';
                } else if((grid[linhas - 1][8] == 'L') && (grid[linhas - 2][8] != '-')){
                    grid[linhas - 2][8] = 'L';
                } else{
                    printf("**morreu**\n");
                    break;
                }
                batidas = 0;
                tronco--;
            }
        } else{
            printf("**beep**\n");
            goto Proximo;
        } 
        borda();
        for(int i = linhas - 5; i < linhas; i++){
            for(int j = 0; j < 11; j++){
                printf("%c", grid[i][j]);
            }
            printf("\n");
        }
        borda();
        Proximo:
        comando = getchar();
        comandosQtd++;
    }
}
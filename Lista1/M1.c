//LUMBERJACK
#include <stdio.h>
#include <stdlib.h>

void borda(){
    for(int i = 0; i < 11; i++){
        printf("~");
    }
    printf("\n");
}

int main(){
    //DATA INPUT
    int tamanho, galhosQtd;
    scanf("%d", &tamanho);
    scanf("%d", &galhosQtd);
    
    char galhos[galhosQtd][2], inicioLenhador, letra, comandos[2001];
    
    for(int i = 0; i < galhosQtd; i++){
        scanf("\n%c %c", &galhos[i][0], &galhos[i][1]);
    }
    scanf("\n%c\n", &inicioLenhador);

    for(int i = 0; i < 2001; i++){
        comandos[i] = ' ';
    }
    fgets(comandos, 2001, stdin);

    //ESTADO INICIAL DO JOGO
    int batidas = 0, estadosQtd = 0, vida = 1, beep[2001];
    char grid[tamanho][11], estadosGrid[2001][tamanho][11];
    
    //Limpando cada caractere da matriz
    for(int i = 0; i < tamanho; i++){
        for(int j = 0; j < 11; j++){
            grid[i][j] = ' ';
        }
    }
    //Limpando cada caractere da matriz de estados
    for(int z = 0; z < 2001; z++){
        for(int j = 0; j < tamanho; j++){
            for(int i = 0; i < 11; i++){
                estadosGrid[z][j][i] = ' ';
            }
        }
    }

    //Tronco da árvore
    for(int i = 0; i < tamanho; i++){
        grid[i][4] = '|';
        grid[i][5] = '|';
        grid[i][6] = '|';
    }
    // Posição inicial do lenhador
    if(inicioLenhador == 'E'){
        grid[tamanho - 1][2] = 'L';
        grid[tamanho - 2][2] = 'L';
    } else if(inicioLenhador == 'D'){
        grid[tamanho - 1][8] = 'L';
        grid[tamanho - 2][8] = 'L';
    }

    //Galhos
    for(int i = 0; i < galhosQtd; i++){
        int temp = galhos[i][1] - '0';

        if(galhos[i][0] == 'E'){
            grid[tamanho - temp][1] = '-';
            grid[tamanho - temp][2] = '-';
            grid[tamanho - temp][3] = '-';
        } else if(galhos[i][0] = 'D'){            
            grid[tamanho - temp][7] = '-';
            grid[tamanho - temp][8] = '-';
            grid[tamanho - temp][9] = '-';
        }
    }
    //Registrando estado inicial
    for(int i = 0; i < tamanho; i++){
        for(int j = 0; j < 11; j++){
            estadosGrid[estadosQtd][i][j] = grid[i][j];
         }
    }
    estadosQtd++;
    beep[0] = 0;

    //Lógica de jogo
    for(int i = 0; i < 2001; i++){
        if(vida == 1){
            if(comandos[i] == ' '){
                continue;
            }
            //Trocar posição do lenhador
            if(comandos[i] == 'T'){
                if((grid[tamanho - 1][2] == 'L') && (grid[tamanho - 2][2] == 'L')){
                    if((grid[tamanho - 1][8] != '-') && (grid[tamanho - 2][8] != '-')){
                            grid[tamanho - 1][2] = ' ';
                            grid[tamanho - 2][2] = ' ';
                            grid[tamanho - 1][8] = 'L';
                            grid[tamanho - 2][8] = 'L';
                            inicioLenhador = 'D';
                            beep[i + 1] = 0;
                            for(int a = 0; a < tamanho; a++){
                                for(int b = 0; b < 11; b++){
                                    estadosGrid[estadosQtd][a][b] = grid[a][b];
                                }
                            }
                            estadosQtd++;
                            continue;
                    } else{
                        beep[i + 1] = 1;
                    }
                }
                else if((grid[tamanho - 1][8] == 'L') && (grid[tamanho - 2][8] == 'L')){
                    if((grid[tamanho - 1][2] != '-') && (grid[tamanho - 2][2] != '-')){
                            grid[tamanho - 1][8] = ' ';
                            grid[tamanho - 2][8] = ' ';
                            grid[tamanho - 1][2] = 'L';
                            grid[tamanho - 2][2] = 'L';
                            inicioLenhador = 'E';
                            beep[i + 1] = 0;
                            for(int a = 0; a < tamanho; a++){
                                for(int b = 0; b < 11; b++){
                                    estadosGrid[estadosQtd][a][b] = grid[a][b];
                                }
                            }
                            estadosQtd++;
                            continue;
                    } else{
                        beep[i + 1] = 1;
                    }
                }
            }

            
            //Batidas
            else if(comandos[i] == 'B'){
                if(batidas < 1){
                    if(inicioLenhador == 'E'){
                        grid[tamanho - 1][4] = '>';
                    } else if(inicioLenhador == 'D'){
                        grid[tamanho - 1][6] = '<';
                    }
                    batidas++;
                    beep[i + 1] = 0;
                    for(int a = 0; a < tamanho; a++){
                        for(int b = 0; b < 11; b++){
                             estadosGrid[estadosQtd][a][b] = grid[a][b];
                        }
                    }
                    estadosQtd++;
                } else{
                    for(int i = tamanho-1 ; i > 0; i--){
                        for(int j = 0; j < 11; j++){
                            grid[i][j] = grid[i-1][j];
                            grid[i-1][j] = ' '; 
                        }
                    }
                    if((grid[tamanho - 1][2] == 'L') && (grid[tamanho - 2][2] != '-')){
                        grid[tamanho - 2][2] = 'L';
                    } else if((grid[tamanho - 1][8] == 'L') && (grid[tamanho - 2][8] != '-')){
                        grid[tamanho - 2][8] = 'L';
                    } else{
                        vida = 0;
                        continue;
                    }
                    batidas = 0;
                    beep[i + 1] = 0;
                    for(int a = 0; a < tamanho; a++){
                        for(int b = 0; b < 11; b++){
                            estadosGrid[estadosQtd][a][b] = grid[a][b];
                        }
                    }
                    estadosQtd++;
                }
            } else{
                beep[i + 1] = 1;
            }
        }
    }
    
    //Imprimindo cada estado na tela
    for(int i = 0; i < estadosQtd; i++){
        printf("beep[%d] = %d\n", i, beep[i]);
        if(beep[i] == 0){
            borda();
            for(int j = tamanho - 5; j < tamanho; j++){
                for(int k = 0; k < 11; k++){
                    printf("%c",estadosGrid[i][j][k]);
                }
                printf("\n");
            }
            borda();   
        } else{
            printf("**beep**\n");
        }
    }
    if(vida == 0){
        printf("**morreu**\n");
    }
    return 0;
}
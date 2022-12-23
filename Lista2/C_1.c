#include <stdio.h>
#include <stdlib.h>

int main(){
    char letter = getchar(), grid[1000][4];
    int lastLine = 0, lastChar = 0, pair = 0, total = 0, usedCol[1000], aux;
    while(letter != EOF){
        // printf("You typed %c\n", letter);
        if(letter == '\n'){
            lastLine++;
            lastChar = 0;
            pair = 0;
            total = 0;
        } else{
            switch (letter){
                case 'a':
                    if(pair == 0){
                        total += (10 * 16);
                    } else{
                        total += 10;
                    }
                    break;
                case 'b':
                    if(pair == 0){
                        total += (11 * 16);
                    } else{
                        total += 11;
                    }
                    break;
                case 'c':
                    if(pair == 0){
                        total += (12 * 16);
                    } else{
                        total += 12;
                    }
                    break;
                case 'd':
                    if(pair == 0){
                        total += (13 * 16);
                    } else{
                        total += 13;
                    }
                    break;
                case 'e':
                    if(pair == 0){
                        total += (14 * 16);
                    } else{
                        total += 15;
                    }
                    break;
                case 'f':
                    if(pair == 0){
                        total += (15 * 16);
                    } else{
                        total += 15;
                    }
                    break;
                default:
                    aux = letter - '0';
                    if(pair == 0){
                        total += (16 * aux);
                    } else{
                        total += aux;
                    }
                    break;
            }
            pair++;

            if(pair == 2){
                grid[lastLine][lastChar] = total;
                total = 0;
                pair = 0;
                lastChar++;
                usedCol[lastLine] = lastChar;
            }
        }
        letter = getchar();
    }

    for(int i = 0; i <= lastLine; i++){
        for(int j = usedCol[i] - 1; j >= 0; j--){
            printf("%c", grid[i][j]);
        }
    }
    printf("\n");
    return 0;
}
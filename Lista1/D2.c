#include <stdio.h>
#include <string.h>

int main(){
    char buffer[4];
    int acc = 0, sim = 0, nao = 0, total = 0, test;
    do{
        test = scanf("%s", buffer);
        if(strcmp(buffer, "sim") == 0){
            sim++;
            acc++;
        } else if(strcmp(buffer, "nao") == 0){
            nao++;
            acc++;
        }
        if(acc == 10 && sim >= 2){
            total ++;
            sim = 0;
            nao = 0;
        }
        if(acc == 10){
            acc = 0;
            sim = 0;
            nao = 0;
        }

    } while(test != -1);


    printf("%d\n", total);
    return 0;
}
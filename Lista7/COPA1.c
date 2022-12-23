#include <stdio.h>

int main(void){
    int left, right;
    char roundOf16[9], quartersOfFinal[5], semifinals[2];
    for(int i = 0; i < 8; i++){
        scanf("%d %d\n", &left, &right);
        if(left > right) roundOf16[i] = 65 + 2*i;
        else roundOf16[i] = 65 + 2*i + 1;
    }
    for(int i = 0; i < 4; i++){
        scanf("%d %d\n", &left, &right);
        if(left > right) quartersOfFinal[i] = roundOf16[2*i];
        else quartersOfFinal[i] = roundOf16[2*i + 1];
    }
    for(int i = 0; i < 2; i++){
        scanf("%d %d\n", &left, &right);
        if(left > right) semifinals[i] = quartersOfFinal[2* i];
        else semifinals[i] = quartersOfFinal[2*i + 1];
    }
    scanf("%d %d\n", &left, &right);
    if(left > right) printf("%c\n", semifinals[0]);
    else printf("%c\n", semifinals[1]);
}
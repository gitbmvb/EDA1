#include <stdio.h>
#include <string.h>

void composeSubstring(char * dest, char * origin, int beg, int len, int acc){
    if(acc >= len){
        *dest = '\0';
        return;    
    }
    *dest = *(origin + beg + acc);
    acc++;
    composeSubstring(&dest[1], origin, beg, len, acc);
}

int biggestStr(char * str, char * sub, int flag, int acc){
    int lensub = strlen(sub);
    int lenstr = strlen(str);
    
    if(lensub > lenstr) return 0;
    if(acc == lenstr && flag == 0) return -lenstr;

    char aux[lensub];
    if(flag == 0) composeSubstring(aux, str, acc, lensub, 0);
    else composeSubstring(aux, str, acc - lensub, lensub, 0);
    if(strcmp(aux, sub) == 0){
        if(flag == 0) return 1;
        return strlen(str);
    }
    else{
        if(flag == 0) return 1 + biggestStr(str, sub, flag, acc + 1);
        return -1 + biggestStr(str, sub, flag, acc - 1);
    }
}

int main(void){
    char str[101], sub[101];
    scanf("%s\n%s", str, sub);
    int qtd = biggestStr(str, sub, 0, 0);
    if(qtd > 0) printf("%d\n", biggestStr(str, sub, 1, strlen(str)) - qtd + 1);
    else printf("0\n");
}
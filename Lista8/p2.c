#include <stdio.h>


int cmp(int ptsA, int ptsB, int rA, int rB){
    if((ptsA > ptsB + rB) || (ptsB > ptsA + rA)) return 1;
    return 0;
}

int main(void){
    int N, ptsA = 0, ptsB = 0, rA, rB, flag = 0;
    scanf("%d", &N);
    rA = rB = N;
    char strA[N+1], strB[N+1];
    scanf("%s\n%s", strA, strB);
    for(int i = 0; i < N; i++){
        if(strA[i] == 'o') ptsA++;
        rA--;
        if(cmp(ptsA, ptsB, rA, rB) == 1){
            printf("%d\n",2 * i + 1);
            flag = 1;
            break;
        }
        if(strB[i] == 'o') ptsB++;
        rB--;
        if(cmp(ptsA, ptsB, rA, rB) == 1){
            printf("%d\n", 2 * i + 2);
            flag = 1;
            break;
        }
    }
    if(flag != 1) printf("Empate\n");
}
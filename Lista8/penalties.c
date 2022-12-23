#include <stdio.h>
#include <string.h>

void countPenalties(int pnlts, char * pnltsA, char * pnltsB){
    int pA = 0, pB = 0, remaining = pnlts;
    for(int i = 0; i < pnlts; i++){
        if(pnltsA[i] == 'o') pA++;
        if(pnltsB[i] == 'o') pB++;
        remaining--;
        int greater = pA, smaller = pB;
        if(pB > pA){
            greater = pB;
            smaller = pA;
        }
        if(greater > smaller + remaining){
            printf("%d\n", 2 * (i + 1));
            return;
        }

    }
    printf("Empate\n");
}

int main(void){
    int pnlts;
    scanf("%d\n", &pnlts);
    char pnltsA[pnlts], pnltsB[pnlts];
    scanf("\n%s\n%s", pnltsA, pnltsB);
    countPenalties(pnlts, pnltsA, pnltsB);
}
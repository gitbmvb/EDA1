#include <stdio.h>

int main(){
    int n, joao = 0, ze = 0, temp1, temp2, index = 0, diffs[100][100], quantities[100];
    scanf("%d", &n);
    while(n != 0){
        for(int i = 0; i < n; i++){
            scanf("%d%d", &temp1, &temp2);
            joao += temp1;
            ze += temp2;
            diffs[index][i] = joao - ze;
        }
        joao = 0;
        ze = 0;
        quantities[index] = n;
        index++;
        scanf("%d", &n);
    }
    printf("\n");
    for(int i = 0; i < index; i++){
        printf("Teste %d\n", i +1);
        for(int j = 0; j < quantities[i]; j++){
            printf("%d\n", diffs[i][j]);
        }
        printf("\n");
    }
    return 0;
}
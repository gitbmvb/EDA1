#include <stdio.h>

int main(){
    int n, x, index = 0, alice = 0, beto = 0, points[10000][2];
    scanf("%d", &n);
    while(n != 0){
        for(int i = 0; i < n; i++){
            scanf("%d", &x);
            if(x == 0){
                alice++;
            } else if(x == 1){
                beto++;
            }
        }
        points[index][0] = alice;
        points[index][1] = beto;
        index++;
        alice = 0;
        beto = 0;
        scanf("%d", &n);
    }
    for(int i = 0; i < index; i++){
        printf("Alice ganhou %d e Beto ganhou %d\n", points[i][0], points[i][1]);
    }
    return 0;
}
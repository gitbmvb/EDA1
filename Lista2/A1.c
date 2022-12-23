#include <stdio.h>

int main(){
    int people, result = 0, temp, answer;
    scanf("%d", &people);
    for(int i = 0; i < people; i ++){
        scanf("%d", &temp);
        result += temp;
    }
    scanf("%d", &answer);
    if(answer == result){
        printf("Acertou\n");
    } else{
        printf("Errou\n");
    }
    return 0;
}
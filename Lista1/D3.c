#include <stdio.h>
#include <stdlib.h>

int main(){
    int pairs, results[200], min_id = 10000000, id, max_rating = 0, rating, index = 0;
    scanf("%d", &pairs);
    do{
        for(int i = 0; i < pairs; i++){
            scanf("%d %d", &id, &rating);
            if(rating >= max_rating && id < min_id){
                min_id = id;
                max_rating = rating;
            }
        }
        results[index] = min_id;
        index++;
        min_id = 10000000;
        max_rating = 0;

    } while((scanf("%d", &pairs)) != EOF);

    for(int i = 0; i < index; i++){
        printf("Dia %d\n", i + 1);
        printf("%d\n\n", results[i]);
    }
    return 0;
}
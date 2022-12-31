#include <stdio.h>
#include <stdlib.h>

int * merge2(int * v1, int * v2, int l1, int l2, int r1, int r2){
    int * aux = malloc(sizeof(int) * (r2 + r1 - l2 -l1 + 2));
    int i_v1 = l1, i_v2 = l2, i_aux = 0;
    while(i_v1 <= r1 && i_v2 <= r2){
        if(v1[i_v1] <= v2[i_v2]) aux[i_aux++] = v1[i_v1++];
        else aux[i_aux++] = v2[i_v2++];
    }
    while(i_v1 <= r1) aux[i_aux++] = v1[i_v1++];
    while(i_v2 <= r2) aux[i_aux++] = v2[i_v2++];
    return aux;
}

int main(){
    int lengths[4], final_len = 0;
    int ** values1 = malloc(sizeof(int*) * 16), ** values2 = malloc(sizeof(int*) * 4), **values3 = malloc(sizeof(int*) * 2);
    for(int i = 0; i < 4; i++){
        int len1 = 0, len2 = 0;
        scanf("%d", &len1);
        values1[2*i] = malloc(sizeof(int) * len1);
        for(int j = 0; j < len1; j++) scanf("%d", &values1[2*i][j]);
        scanf("%d", &len2);
        values1[2*i + 1] = malloc(sizeof(int) * len2);
        for(int j = 0; j < len2; j++) scanf("%d", &values1[2*i + 1][j]);
        values2[i] = malloc(sizeof(int) * (len1 + len2));
        values2[i] = merge2(values1[2*i], values1[2*i + 1], 0, 0, len1 - 1, len2 - 1);
        lengths[i] = len1 + len2;
        free(values1[2*i]);
        free(values1[2*i + 1]); 
    }
    for(int i = 0; i < 2; i++){
        values3[i] = malloc(sizeof(int) * (lengths[2*i] + lengths[2*i+1]));
        values3[i] = merge2(values2[2*i], values2[2*i+1], 0, 0, lengths[2*i] - 1, lengths[2*i + 1] - 1);
        final_len += (lengths[2*i] + lengths[2*i + 1]);
    }
    int * v_final = malloc(sizeof(int) * final_len);
    v_final = merge2(values3[0], values3[1], 0, 0, lengths[0] + lengths[1] - 1, lengths[2] + lengths[3] - 1);

    for(int i = 0; i < final_len; i++){
        printf("%d ", v_final[i]);
        if(i + 1 < final_len) printf(" ");
        else printf("\n");
    }
    return 0;
}

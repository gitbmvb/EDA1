#include <stdio.h>

int main(){
    int v[1000], i = 0;
    while(scanf("\n%x", v + i) == 1){
        char * ptr = v;
        printf("%s", ptr);
    }
    printf("\n");
    return 0;
}
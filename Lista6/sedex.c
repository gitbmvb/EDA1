#include <stdio.h>

int main(){
    unsigned short diameter, height, width, depth;
    scanf("\n%hd", &diameter);
    scanf("\n%hd %hd %hd", &height, &width, &depth);
    if(height >= diameter && width >= diameter && depth >= diameter)
        printf("S\n");
    else printf("N\n");
    return 0;
}
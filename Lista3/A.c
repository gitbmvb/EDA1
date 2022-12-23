#include <stdio.h>

int f91(int n){
    if(n >= 101)
        return n  - 10;
    else return f91(f91(n + 11));
}

int main(){
    int number;
    scanf("\n%d", &number);
    while(number != 0){
        printf("f91(%d) = %d\n", number, f91(number));
        scanf("\n%d", &number);
    }

    return 0;
}
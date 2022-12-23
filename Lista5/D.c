#include <stdio.h>
#include <string.h>

int inicio = -1, final = -1;

// void subStringCompare(char * str, char * substr){
//     int len = strlen(substr);
//     char aux[len+1];
//     memcpy(aux, &str[0], len);
//     aux[len] = '\0';
//     if(strcmp(substr, aux) != 0) total += len;
//     subStringCompare(str+len, substr);
    
// }

void subStringCompare(char * str, char * substr){
    int len = strlen(substr);
    char aux[len+1];
    memcpy(aux, &str[0], len);
    aux[len] = '\0';
    


    
}


int main(){
    char str[101], substr[101];
    scanf("%s\n%s", str, substr);
    subStringCompare(str, substr);
    return 0;
}
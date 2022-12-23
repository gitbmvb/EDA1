#include <stdio.h>
#include <string.h>


int bem_formada(char * string){
    char fila[strlen(string)];
    int aux = 0;
    for(int i = 0; i < strlen(string); i++){
        if(string[i] == '(' || string[i] == '[' || string[i] == '{'){
            fila[aux] = string[i];
            aux++;
        } else if(string[i] == ')' || string[i] == ']' || string[i] == '}')
            if(fila[aux-1] == '(' && string[i] == ')'){
                aux--;
            } else if(fila[aux-1] == '[' && string[i] == ']'){
                aux--;
            } else if(fila[aux-1] == '{' && string[i] == '}'){
                aux--;
            } else{
                return 0;
            }
    }
    return 1;
}

int main(){
    char myString[5] = "([)]";
    printf("%d\n", bem_formada(myString));
    return 0;
}
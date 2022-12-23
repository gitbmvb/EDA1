#include <stdio.h>
#include <string.h>

int main(){
   char buffer[30];
   char thereIsMars = 1;
   int test;


   do{
      test = scanf("%s", buffer);
      if(strcmp(buffer, "marte") == 0 && thereIsMars != 0){
         thereIsMars = 0;
      }
   } while(test != -1);

   if(thereIsMars == 0){
      printf("Leonardo Cicero Marciano\n");
   } else{
      printf("none\n");
   }

   return 0;
}
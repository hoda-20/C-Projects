#include <stdio.h> 
#include <conio.h>



int main (){ 
   char ch ; 
   char pass[20] ; 
   int i ; 
   printf("Please enter the password \n ");
    ch = _getch();
   while (ch != 13 ){
     pass[i]= ch ; 
     i++; 

   }

  pass[i] = '\0' ; 
  printf("your password is : %s", pass ); 


    return 0 ; 
}
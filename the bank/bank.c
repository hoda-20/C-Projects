#include <stdio.h> 
#include <conio.h>
#include <string.h>
#include <windows.h>

//functions 
char* password(); 
void testPassword();
void load (); 
int mainMenu() ; 

//structures
typedef struct account ; 

//variables 
char correctPassword[20] = "123"; 


int main (){

 //testPassword() ; 
 //load (); 
 mainMenu();
 switch (mainMenu())
 {
 case  1 :
    /* code */
    break;
 
 default:
    break;
 }

 


    return 0 ; 
}

char* password (){
   char ch ; 
   static char pass[20] ; 
   int i= 0 ;
    
   
   
   printf("\nPlease enter the password \n ");
    // 13 : enter in ascii , 8 : delete in ascii 
   while ((ch = _getch()) != 13 ){
     if (ch != 8 ){
        pass[i]= ch ; 
        i++; 
        printf("*");
        
     }
     else  {
        i-- ;
        pass[i]= '\0' ;
        printf("\b \b");

     }
   }
  pass[i] = '\0' ; 
  return pass ; 
 
  //printf("your password is : %s", pass ); 
}

void testPassword (){
   
   
   //printf("the pass is %s" , password());

   while (strcmp (correctPassword , password() ) !=0 ){
      
    printf("\nnaah wrong password dear ! , try again   "); 
   
   } 
}

void load ( ){

  printf("\nloading") ; 
  for (int i = 0 ; i < 5 ; i++ ){
    printf("."); 
    Sleep(1000); 
    
  } 
}

int mainMenu (){
static int b ; 
 printf("                        ");
 printf("\033[;4;33mCustumor account banking management system\033[0m\n");
 printf("                                  ");
 printf("\033[1;4;36mThis is your main menu\033[0m\n");
 printf("\033[;32m1:Creat new account\033[0m\n");
 printf("\033[;32m2:Update information of existing account\033[0m\n");
 printf("\033[;32m3:Transactions\033[0m\n");
 printf("\033[;32m4:Check the details of existing account\033[0m\n");
 printf("\033[;32m5:Delete existing account\033[0m\n");
 printf("\033[;32m6:View customer's list\033[0m\n");
 printf("\033[;32m7:Exit\033[0m\n");
 printf("          ");
 printf("\033[1;36mEnter your choice please:\033[0m\n");
 
 scanf("%d", &b);
 return b ; 
}

typedef struct account {
   char date[10] ; 
   int  accNum ; 
   char name[20] ; 
   char dateBirth[10]; 
   int age ; 
   char adress[20];
   int citizenshipNum ; 
   int phoneNum ; 
   int accDeposit ; 
   int amountDeposit ; 
   int accType ; 
   
}

































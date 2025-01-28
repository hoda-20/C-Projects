#include <stdio.h> 
#include <conio.h>
#include <string.h>
#include <windows.h>

//functions 
char* password(); 
void testPassword();
void load (); 
int mainMenu() ; 
void makeNewAccount();

//structures
typedef struct {
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
} newAccount;

//variables 
char correctPassword[20] = "123"; 


int main (){

 //testPassword() ; 
 //load (); 
 //mainMenu();
 //makeNewAccount();
    newAccount account[50] ; 
   for (int i= 0; i<50 ; i++ ){

   printf("Enter today's date : "); 
   scanf("%s", account[i].date);
   fflush(stdin); 
   printf("\nEnter the account number : ");
   scanf("%d", &account[i].accNum ); 
   fflush(stdin); 
   printf("\nEnter your name : "); 
   scanf("%s" , account[i].name);
   fflush(stdin); 
   printf("\n Enter date of birth :");
   scanf("%s" , account[i].dateBirth);
   fflush(stdin); 
   printf("\n Enter your age :");
   scanf("%d" , &account[i].age); 
   fflush(stdin); 
   printf("\n Enter your adress :");
   scanf("%s" , account[i].adress);
   fflush(stdin); 
   printf("\n Enter citizenship number :");
   scanf("%d" , &account[i].citizenshipNum);
   fflush(stdin); 
   printf("\n Enter your phone number :");
   scanf("%d" , &account[i].phoneNum);
   fflush(stdin); 
   printf("\n Enter the amount to deposit :");
   scanf("%d" , &account[i].amountDeposit);
   fflush(stdin); 
   printf("\n Type of account : \n -Saving \n -Current \n -Fixed1 (for 1 year) \n -Fixed2 (for 2 years) \n -Fixed3 (for 3 years) \n     Enter your choice : ");
   scanf("%s" , account[i].accType); 
   fflush(stdin); 
   printf("\n Account created successfully :)"); 

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



/*void makeNewAccount ( ){
   static  newAccount account[50] ; 
    

   for (int i= 0 ; i<50 ; i++ ){

   printf("Enter today's date : "); 
   scanf("%s", &account[i].date);
   printf("\nEnter the account number : ");
   scanf("%d", &account[i].accNum ); 
   printf("\nEnter your name : "); 
   scanf("%s" , &account[i].name); 
   printf("\n Enter date of birth :");
   scanf("%s" , &account[i].dateBirth);
   printf("\n Enter your age :");
   scanf("%d" , &account[i].age); 
   printf("\n Enter your adress :");
   scanf("%s" , &account[i].adress);
   printf("\n Enter citizenship number :");
   scanf("%d" , &account[i].citizenshipNum);
   printf("\n Enter your phone number :");
   scanf("%d" , &account[i].phoneNum);
   printf("\n Enter the amount to deposit :");
   scanf("%d" , &account[i].amountDeposit);
   printf("\n Type of account : \n -Saving \n -Current \n -Fixed1 (for 1 year) \n -Fixed2 (for 2 years) \n -Fixed3 (for 3 years) \n     Enter your choice : ");
   scanf("%s" , &account[i].accType); 

   printf("\n Account created successfully :)"); 

   }

}*/

































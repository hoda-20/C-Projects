#include <stdio.h> 
#include <conio.h>
#include <string.h>
#include <windows.h>
#include <time.h>


//variables 
char correctPassword[20] = "123"; 
int N = 50 ; 
int M =0; 


//structures
typedef struct { 
   int  accNum ; 
   char name[20] ; 
   char dateBirth[10]; 
   int age ; 
   char adress[30];
   int citizenshipNum ; 
   int phoneNum ; 
   int accDeposit ; 
   int amountDeposit ; 
   char accType[20] ; 
   char dateDeposite[20];
} newAccount;

//functions 
char* password(); 
void  testPassword();
void  load (); 
char   mainMenu() ; 
void  makeNewAccount(newAccount *account);
void  checkExistingAccount(newAccount *account); 
void  userChoice();
void  PrintAccountInfos(newAccount *account , int i );
void  ChangeAccountInfo(newAccount *account);
void  GetDate(char CurrentDate[]);
void  Transactions(newAccount *acccount); 
void  ClearScreen() ;
void  CustumorList(newAccount *account);
void  clearInputBuffer() ;
void  DeleteAccount(newAccount *account); 




int main (){
   //Variables : 
    newAccount account[N]; 
    char choice ; 

   //Password
    ClearScreen();
    testPassword(); 
    load();

   //Menu and Accounts 
      do {
         choice = mainMenu();
         switch (choice)
         {
            
         case '1':
            ClearScreen();
            makeNewAccount(account);
            break;

         case '2' : 
            ClearScreen();
            ChangeAccountInfo(account);
         break ; 

         case '3' : 
            ClearScreen();
            Transactions(account); 
         break ;
        
         case '4' :
            ClearScreen();
            checkExistingAccount(account);
         break ;

         case '5' : 
          ClearScreen(); 
          DeleteAccount(account ); 
          break ;

          case '6' :
          ClearScreen(); 
          CustumorList(account);
          break ; 

          

         case '7' : 
         printf("------exiting programme");
         for(int j = 0 ; j < 6 ; j++ ){
           printf("-"); 
           Sleep(1000);  
         } 
         exit(0);
         break; 

         default:
         ClearScreen();
         printf("Invalid choice! Choose from the list above please.\n");
         printf("Press any key to continue...");
         _getch(); 
         
         break; 
            
            
         
         }



      }while(1);
    
    return 0 ; 
}

//Password functions
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
 
  
}

void testPassword (){
   
   
   

   while (strcmp (correctPassword , password() ) !=0 ){  
    printf("\nWrong password"); 
   
   } 
   printf("\nCorrect password !");
}

void load ( ){ 
  
   printf("\nloading") ; 
  for (int i = 0 ; i < 5 ; i++ ){
    printf("."); 
    Sleep(1000); 
    
  } 
}


// Menu functions 
char mainMenu (){
   ClearScreen();
 char choice; 
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
 printf("\033[1;36mEnter your choice please:\033[0m  ");
 
 scanf(" %c", &choice);
 clearInputBuffer();
 return choice ; 
}

void makeNewAccount (newAccount *account){
     
    
     int  choice  ; 

   static int i = 0 ; 
    while (i<N){

   printf("-------Custumor number %d---------",i);
   printf("\n Enter today's date : "); 
   scanf("%s", &account[i].dateDeposite);
   printf("\n Enter the account number : ");
   scanf("%d", &account[i].accNum ); 
   printf("\n Enter your name : "); 
   scanf("%s" , &account[i].name); 
   printf("\n Enter date of birth (day/month/year) :");
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
   scanf("%s" , account[i].accType); 

   printf("\n Account created successfully :)\n"); 
   M++ ; 
   i++ ; 
   break ; 
   }
   
   userChoice();

   

}

void ChangeAccountInfo(newAccount *account){
   int accNum , choice , choice1 , newPhoneNumber; 
   int found = 0 ; 
   char newAdress[20];
  
   printf("Enter the account number of the custumor whose informations you want to change :  "); 
   scanf("%d",&accNum);
  //look for the account 
  for (int i = 0 ; i<N ; i++){
     if (accNum == account[i].accNum ){
      found = 1 ;
      do{ printf("which information do you want to change ?\n 1:Adress\n 2:Phone number "); 
          scanf("%d",&choice1); 
   }while(choice1!= 1 && choice1!=2);
     

     if (choice1==1){
         printf("\nEnter the new adress : "); 
         scanf("%s",newAdress);
         strcpy(account[i].adress , newAdress);
         printf("Adress changed !"); 
         break;

     }else if (choice1 == 2 ){
         printf("Enter the new phone number : ");
         scanf("%d",&newPhoneNumber); 
         account[i].phoneNum = newPhoneNumber ; 
         printf("Phone number changed !");
         break;


     }
   }
  }
  //account does not exist 
  if (found == 0 ){
   printf("account does not exist , enter a key to return to the main menu and make an account , or 0 to exit \n");
   scanf("%d",&choice); 
   if (choice == 0 ){
         printf("------exiting programme");
         for(int j = 0 ; j < 6 ; j++ ){
           printf("-"); 
           Sleep(1000);  
         } 
         exit(0);
     
   }else {return ; }
}
   
  userChoice();

}

void Transactions(newAccount *account){
   
   int accNum , choice1 , deposite =0, choice , withraw =0;
   int found = 0 ;  
   
   printf("Enter the account number of the custumor : "); 
   scanf("%d", &accNum); 
   
   
  //look for the account 
  for (int i = 0 ; i<N ; i++){
     if (accNum == account[i].accNum ){
      found = 1 ;
      do{ printf("Do you want to :\n 1:Deposite\n 2:Withraw "); 
          scanf("%d",&choice1); 
   }while(choice1!= 1 && choice1!=2);
     

     if (choice1==1){
         printf("\nEnter the amount you want to deposite: "); 
         scanf("%d",&deposite);
         account[i].amountDeposit = account[i].amountDeposit+ deposite ; 
         GetDate(account[i].dateDeposite);
         printf("Deposited successfully"); 
         break;

     }else if (choice1 == 2 ){
         printf("Enter the amount to withraw : ");
         scanf("%d",&withraw); 
         account[i].amountDeposit = account[i].amountDeposit-withraw ; 
         GetDate(account[i].dateDeposite);
         printf("Withrawed syccessfully !");
         break;


     }
   }
  }
  //account does not exist 
  if (found == 0 ){
   printf("account does not exist , enter a key to return to the main menu and maek an account , or 0 to exit \n");
   scanf("%d",&choice); 
   if (choice == 0 ){
         printf("------exiting programme");
         for(int j = 0 ; j < 6 ; j++ ){
           printf("-"); 
           Sleep(1000);  
         } 
         exit(0);
     
   }else {return ; }
 

}
 userChoice();
}

void checkExistingAccount(newAccount *account){
   int choice , acNum  ;
   int found = 0 ; 
   char name[30];
    do { printf("Do you want to check by :\n1:Account number\n2:Name  "); 
         scanf("%d",&choice); 
   }while (choice !=1 && choice !=2);

      //Search by account number 
   if (choice == 1 ){
      printf("Enter the account number "); 
      scanf("%d",&acNum); 
      for (int i = 0 ; i < N ; i++ ){
      if (account[i].accNum == acNum ){
            PrintAccountInfos(account , i);
            found = 1 ; 
            break;
      }
   }
       if (found == 0 ){ printf("Account not found , please return to the main menu to creat one ") ;}

      //Search by name
   } else if (choice == 2 ){
      printf("Enter the name "); 
      scanf("%s", &name); 

      for (int i = 0 ; i < N ; i++ ){
         if ((strcmp(name,account[i].name))==0 ){
            PrintAccountInfos(account , i); 
               found = 1 ; 
               break ; 
         } 
    }
         if (found == 0 ){printf("Account not found ! Please return to the main menu to creat one "); }
} 
   userChoice();

}

void  DeleteAccount(newAccount *account ){
   int found = 0 , accNum ;
   char choice ; 
   printf("Enter the account number of the custumor whose informations you want to delete :  "); 
   scanf("%d",&accNum);
   for (int i = 0 ; i < N ; i++ ){
      if (account[i].accNum == accNum){
         found = 1 ; 
         for (int j = i ; j<N ; j++){
            account[j] = account[j+1]; 

         }
      }
  }
      
      if (found == 1 ){ 
       M--;  
       printf("Account deleted successfully!\n"); 
        userChoice(); 
      }
      
         
      if (found == 0 ){
         printf("account does not exist , enter a key to return to the main menu and make an account , or 0 to exit \n");
         scanf(" %c",&choice);
         clearInputBuffer(); 

         if (choice == '0' ){
               printf("------exiting programme");
               for(int k = 0 ; k < 6 ; k++ ){
                 printf("-"); 
                 Sleep(1000);  
               } 
               exit(0);
           
         }else {return ; }
      
      }
       
}

void CustumorList(newAccount *account){
   printf("Number of accounts created up till now : %d\n",M);
   printf("+------------+------------+---------------+------------+------------+\n");
   printf("| Acc Number | Name       | Phone         | Address    | Deposit    |\n");
   printf("+------------+------------+---------------+------------+------------+\n");
   for (int i = 0 ; i< M ; i++ ){
      printf("| %-10d | %-10s | %-13d | %-10s | %-10d |\n",
         account[i].accNum, account[i].name, account[i].phoneNum, account[i].adress, account[i].amountDeposit);

   }
   printf("+------------+------------+---------------+------------+------------+\n");
   userChoice();
}


// Other functions 

void userChoice(){
   char choice;
   printf("\nEnter a key to return to the main menu and 0 to exit : ");  
   scanf(" %c",&choice); 
   clearInputBuffer();

   if (choice =='0'){
       printf("------exiting programme");
       for(int j = 0 ; j < 6 ; j++ ){
         printf("-"); 
         Sleep(1000);  
       } 
       exit(0);
   }

}

void PrintAccountInfos(newAccount *account , int i ){
   printf("\n--- Account Details ---\n"); 
   printf("Account Number: %d\n", account[i].accNum);
   printf("Name: %s\n", account[i].name);
   printf("Date of Birth: %s\n", account[i].dateBirth);
   printf("Age: %d\n", account[i].age);
   printf("Address: %s\n", account[i].adress);
   printf("Citizenship Number: %d\n", account[i].citizenshipNum);
   printf("Phone Number: %d\n", account[i].phoneNum);
   printf("Account Type: %s\n", account[i].accType);
   printf("Amount Deposited: %d\n", account[i].amountDeposit);
   printf("Date of deposite: %s\n", account[i].dateDeposite);

   printf("-----------------------\n");
}

void GetDate(char CurrentDate[]){

   time_t t ; //store time
   time(&t) ; // get time 
   struct tm *today = localtime(&t); // convert 
   sprintf(CurrentDate, "%02d/%02d/%04d", today->tm_mday, today->tm_mon + 1, today->tm_year + 1900); // store date in CurrentDate

}

void ClearScreen() {
   system("cls"); 
}

void clearInputBuffer() {
   while (getchar() != '\n'); // Clear all characters until newline
}









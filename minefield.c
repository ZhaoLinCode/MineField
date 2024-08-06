/******************************************************************************

Welcome to GDB Online.
  GDB online is an online compiler and debugger tool for C, C++, Python, PHP, Ruby, 
  C#, OCaml, VB, Perl, Swift, Prolog, Javascript, Pascal, COBOL, HTML, CSS, JS
  Code, Compile, Run and Debug online from anywhere in world.

*******************************************************************************/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define size 8
#define mine 8


 int table[size][size];
 int copyTable[size][size];
 void initializeMines();
 void makeTable();
 void zeroEraser(int i,int j);
 void exploreMindField(int i,int j);

void makeFlag(int i,int j){
 table[i][j] = 9;
 copyTable[i][j] = table[i][j];
}

 void zeroEraser(int i,int j){
  
  if( i >0 && j >0 ){
    copyTable[i-1][j-1] = table[i-1][j-1];
   
    
  } 
  if( i >0 ){
   copyTable[i-1][j] = table[i-1][j];

    
  }  
    if( i >0 && j <size-1 ){
            copyTable[i-1][j+1] = table[i-1][j+1];

    
  }
    if(j >0 ){
         copyTable[i][j-1] = table[i][j-1];
   
 
    
  }
    if(  j <size-1 ){
            copyTable[i][j+1] = table[i][j+1];

    
  }
    if( i <size -1 && j >0 ){
            copyTable[i+1][j-1] = table[i+1][j-1];


    
  }
    if( i <size-1 ){
            copyTable[i+1][j] = table[i+1][j];

 
    
  }
    if( i <size-1 && j <size -1 ){
            copyTable[i+1][j+1] = table[i+1][j+1];

  
    
  }   
 }
 void exploreMindField(int i,int j){

   
copyTable[i][j]= table[i][j];
if(table[i][j] == 0){
zeroEraser(i,j);
}
 }
 
 
 
 void makeLowerTable(){
    int i;
    int j;
    for(i=0;i<size;i++){
     for(j=0;j<size;j++){
 copyTable[i][j] = 8;

    }
 }
 }   
 
 void printLowerTable(){
    int i;
    int j;
    int k = 0;
    for(i=0;i<size;i++){
     for(j=0;j<size;j++){
printf("%d   ",copyTable[i][j]);
     if(j==7){
       printf("  %d",k);
      k++;  
     }
    }
   printf("\n\n");    
 }
 }
void makeTable(){

 int i;
 int j;
 int count;
 for( i = 0;i<size;i++)   {
for( j = 0;j<size;j++) {  
    table[i][j] = 0;
}
 }
initializeMines();
 for( i = 0;i<size;i++)   {
for( j = 0;j<size;j++) {  
  count = 0;  
  if(table[i][j] != -1 && i >0 && j >0 &&table[i-1][j-1]== -1){
    count++;  
    
  }
  if(table[i][j] != -1 && i >0  &&table[i-1][j]== -1){
    count++;  
    
  }
  if(table[i][j] != -1 && i >0 && j<size-1  &&table[i-1][j+1]== -1){
    count++;  
    
  }
  if(table[i][j] != -1  && j >0 &&table[i][j-1]== -1){
    count++;  
    
  }
  if(table[i][j] != -1  && j<size-1  &&table[i][j+1]== -1){
    count++;  
    
  }
  if(table[i][j] != -1 && i <size-1 && j>0  &&table[i+1][j-1]== -1){
    count++;  
    
  }
  if(table[i][j] != -1 && i <size -1  &&table[i+1][j]== -1){
    count++;  
    
  }
  if(table[i][j] != -1 && i <size-1 && j<size-1  &&table[i+1][j+1]== -1){
    count++;  
    
  }
  if(count!= 0){
    table[i][j] = count;  
  }
   count = 0;
}
 }
}
void initializeMines(){
    srand(time(0));
   int randomNum1;
    int randomNum2;

    int m = mine;
    while(m!= 0){
         randomNum1= rand() % 8;
     randomNum2 = rand() % 8;   
     table[randomNum1][randomNum2] = -1;
     m--;
    }
    
}
void printTable(){
    int i;
    int j;
    for(i=0;i<size;i++){
     for(j=0;j<size;j++){
                 if(table[i][j]!=-1){

        printf("%d   ",table[i][j]);
                 }
        else{
                printf("%d  ",table[i][j]);

        }
    } 
printf("\n\n");  
    }
    
}




int main(){
int remainingMine = 8;
int i;
int j;
int decision;
makeTable();
printf("Welcome to MineField!!!\n\n");
printf("--------------------------------  row\n");

makeLowerTable();
printLowerTable();
printf("--------------------------------\n\n");
printf("0   1   2   3   4   5   6   7\n");

printf("Which box will you open? \n\n");
printf("Enter the row: \n");
scanf("%d",&i);
printf("Enter the column: \n");
scanf("%d",&j);
while (table[i][j] !=-1 &&remainingMine!= 0){
exploreMindField(i,j);
printf("--------------------------------  row\n");
printLowerTable();
printf("--------------------------------\n\n");
printf("0   1   2   3   4   5   6   7\n");

printf(" To make flag press 1 \n\n");
printf(" To choose area press 0\n\n");
scanf(" %d", &decision);
if(decision== 1){
printf("Enter the row: \n");
scanf("%d",&i);
printf("Enter the column: \n");
scanf("%d",&j);  
if (table[i][j] != -1){
printf("That area is not have any mine\n");
break;
}
else{
remainingMine--;
makeFlag(i,j);
printf("--------------------------------  row\n");
printLowerTable();
printf("--------------------------------\n\n");
printf("0   1   2   3   4   5   6   7\n");

}
}
if(decision==0){
printf("Which box will you open? \n\n");
printf("Enter the row: \n");
scanf("%d",&i);
printf("Enter the column: \n");
scanf("%d",&j);
}
}
if(remainingMine == 0){
printf("YOU WON CONGRATULATIONS!!!!!\n");
}
else{
    printf("YOU LOSE \n");
}


return 0;
}
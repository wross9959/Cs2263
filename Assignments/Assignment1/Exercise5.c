#include <stdio.h>
#include <ctype.h>
#include <string.h>

void printArr(char a[], int n){
    //just a for loop to go through char array
    for(int i = 0; i < (n-1); i++){
        putchar(a[i]);
    } 

    //new line after complete
    putchar('\n');
}
void printReversed(int n){
    if(n <= 0){
        //new line after complete        
        putchar('\n');   
    }
    else{
        //prints the value of mod n which will be the last digit
        putchar('0' + n % 10);

        //calls method again until n is empty
        printReversed(n /= 10);
    }
}
int convertInt(char a[], int n){

    //int value to return
    int toReturn = 0;

    //to get num values
    for(int i = (n-1); i >= 0 && isdigit(a[i]); i--){

        toReturn = (a[i] - '0') + 10 * toReturn;
    }
    return toReturn;
}
int addReversedInt(char a[], int n, char b[], int m){

    int num1 = convertInt(a, n);
    int num2 = convertInt(b, m);
    return num1 + num2;
    
}
void calculator(){

    //exercise 5
    char message[] = "\nEnter to unsigned interger numbers: ";    
    int promtLength = sizeof(message)/sizeof(message[0]);
    printArr(message, promtLength);


    char num1[10];
    char curr;
    int i = 0;
    while ((curr = getchar()) != '\n' && i < 9) { // 9 to leave space for null terminator
        num1[i++] = curr;
    }
    num1[i] = '\0';
    
    i = 0;
    char num2[10];
    while ((curr = getchar()) != '\n' && i < 9) { // 9 to leave space for null terminator
        num2[i++] = curr;
    }
    num2[i] = '\0';


    int num1Length = strlen(num1);
    int num2Length = strlen(num2);
    int result = addReversedInt(num1, num1Length, num2, num2Length);
    char resultMes[] = "Results: ";
    int resultMesLength = sizeof(resultMes)/sizeof(resultMes[0]);
    
    printArr(resultMes, resultMesLength);
    printReversed(result);
}
int main(){
    calculator();
    return 0;
}
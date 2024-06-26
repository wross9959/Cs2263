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
    //gets the sum of the char integers
    int num1 = convertInt(a, n);
    int num2 = convertInt(b, m);
    return num1 + num2;
    
}
void inputRead(char input[]){
    char curr;
    int i = 0;

    //reads in values until there is a newline
    while ((curr = getchar()) != '\n' && i < 9) { 
        input[i++] = curr;
    }
    //ends
    input[i] = '\0';
}
void calculator(){

    //start message
    char message[] = "\nEnter to unsigned interger numbers: ";    
    int promtLength = sizeof(message)/sizeof(message[0]);
    printArr(message, promtLength);

    //set num arrays for the user inputs 
    char num1[10];
    char num2[10];

    //function to read in values
    inputRead(num1);
    inputRead(num2);

    //gets string length of our inputs 
    int num1Length = strlen(num1);
    int num2Length = strlen(num2);

    //gets the sum of the added reversed nums
    int result = addReversedInt(num1, num1Length, num2, num2Length);

    //Final message code
    char resultMes[] = "Results: ";
    int resultMesLength = sizeof(resultMes)/sizeof(resultMes[0]);
    printArr(resultMes, resultMesLength);

    //prints the results of the reversed Int
    printReversed(result);
}
int main(){

    //calls our calculator class
    calculator();
    return 0;
}
#include <stdio.h>

void printReversed(int n){
    if(n <= 0){
        //to stop recursive 
        putchar(' ');
    }
    else{
        //prints the value of mod n which will be the last digit
        putchar('0' + n % 10);

        //calls method again until n is empty
        printReversed(n /= 10);
    }
    //new line after complete
    putchar('\n');
}
void printArr(char a[], int n){
    //just a for loop to go through char array
    for(int i = 0; i < (n-1); i++){
        putchar(a[i]);
    } 

    //new line after complete
    putchar('\n');
}
int main(){

    //exercise 1
    char message[] = "Hello World";    
    int arrayLength = sizeof(message)/ sizeof(message[0]);
    printArr(message, arrayLength);

    //exercise 2
    int number = 22063;
    printReversed(number);

    return 0;
}
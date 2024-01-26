#include <stdio.h>


void convertInt(char a[], int n){

    for(int i = 0; i < (n-1); i++){
        putchar((a[i] - '0'));
    }
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

    //exercise 3
    char a[] = {'3','2','1'};
    int arrayIntLength = sizeof(a)/ sizeof(a[0]);
    convertInt(a, arrayIntLength);

    return 0;
}
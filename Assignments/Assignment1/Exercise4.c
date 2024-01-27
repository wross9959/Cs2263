#include <stdio.h>
#include <ctype.h>
   
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
int reverseInt(int num) {
    int reversed = 0;
    while (num != 0) {
        int curr = num % 10;
        reversed = reversed * 10 + curr;
        num /= 10;
    }
    return reversed;
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
    int arrayALength = sizeof(a)/ sizeof(a[0]);
    int value = convertInt(a, arrayALength);
    printReversed(reverseInt(value));

    //exercise 4
    char b[] = {'6','5','4'};
    int arrayBLength = sizeof(b)/ sizeof(b[0]);
    int sum = addReversedInt(a, arrayALength, b, arrayBLength);
    printReversed(reverseInt(sum));


    return 0;
}
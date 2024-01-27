#include <stdio.h>

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

    int number = 1;
    int number1 = 100021;
    int number2 = 1263;
    int number3 = 2263;

    //test 1
    //printReversed(number);

    //test 2
    //printReversed(number1);

    //test 3
    //printReversed(number2);

    //test 4
    //printReversed(number3);

    return 0;
}
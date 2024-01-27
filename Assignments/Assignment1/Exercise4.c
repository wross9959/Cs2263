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
int convertInt(char a[], int n){

    //int value to return
    int toReturn = 0;

    //to get num values
    for(int i = n - 1; i >= 0 && isdigit(a[i]); i--){

        toReturn = (a[i] - '0') + 10 * toReturn;
    }
    return toReturn;
}
int printInt(int num) {
    //method to reverse integers to get them read to be printed
    int reversed = 0;
    while (num != 0) {
        int curr = num % 10;
        reversed = reversed * 10 + curr;
        num /= 10;
    }
    printReversed(reversed);
}
int addReversedInt(char a[], int n, char b[], int m){
    //runs both inputs through convert int and added the sum
    int num1 = convertInt(a, n);
    int num2 = convertInt(b, m);
    return (num1 + num2);
    
}
int main(){
    char one[] = "\nTest 1:";
    char two[] = "\nTest 2:";
    char three[] = "\nTest 3:";
    char four[] = "\nTest 4:";
    int testSize = 10;

    // Test 1
    printArr(one, testSize);
    
    char a[] = {'3','2','1'};
    int arrayALength = sizeof(a)/ sizeof(a[0]);
    char b[] = {'6','5','4'};
    int arrayBLength = sizeof(b)/ sizeof(b[0]);
    printInt(addReversedInt(a, arrayALength, b, arrayBLength));

    // Test 2 
    printArr(two, testSize);
    
    char a1[] = {'3','5','3'};
    int arrayA1Length = sizeof(a1)/ sizeof(a1[0]);
    char b1[] = {'0','1','9'};
    int arrayB1Length = sizeof(b1)/ sizeof(b1[0]);
    printInt(addReversedInt(a1, arrayA1Length, b1, arrayB1Length));

    // Test 3
    printArr(three, testSize);

    char a2[] = {'3','3','3'};
    int arrayA2Length = sizeof(a2)/ sizeof(a2[0]);
    char b2[] = {'6','8','1'};
    int arrayB2Length = sizeof(b2)/ sizeof(b2[0]);
    printInt(addReversedInt(a2, arrayA2Length, b2, arrayB2Length));

    // Test 4
    printArr(four, testSize);

    char a3[] = {'1','2','1','2'};
    int arrayA3Length = sizeof(a3)/ sizeof(a3[0]);
    char b3[] = {'6','5','4'};
    int arrayB3Length = sizeof(b3)/ sizeof(b3[0]);
    printInt(addReversedInt(a3, arrayA3Length, b3, arrayB3Length));

    return 0;
}
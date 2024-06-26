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

int main(){
    char one[] = "\nTest 1:";
    char two[] = "\nTest 2:";
    char three[] = "\nTest 3:";
    char four[] = "\nTest 4:";
    int testSize = 10;

    // Test 1
    printArr(one, testSize);
    
    char a[] = {'3','2','1'};
    int arrayIntLength = sizeof(a)/ sizeof(a[0]);
    printInt(convertInt(a, arrayIntLength));

    // Test 2 
    printArr(two, testSize);
    
    char a1[] = {'1', '2', '3'};
    int len1 = sizeof(a1) / sizeof(a1[0]);
    printInt(convertInt(a1, len1));

    // Test 3
    printArr(three, testSize);

    char a2[] = {'5'};
    int len2 = sizeof(a2) / sizeof(a2[0]);
    printInt(convertInt(a2, len2));

    // Test 4
    printArr(four, testSize);

    char a3[] = {'0', '0', '7'};
    int len3 = sizeof(a3) / sizeof(a3[0]);
    printInt(convertInt(a3, len3));

    return 0;

}
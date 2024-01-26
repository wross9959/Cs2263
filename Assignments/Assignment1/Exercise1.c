#include <stdio.h>

void printArr(char a[], int n){

    for(int i = 0; i < (n-1); i++){
        putchar(a[i]);
    }
    
}

int main(){
    char message[] = "Hello World";    
    int arrayLength = sizeof(message)/ sizeof(message[0]);
    printArr(message, arrayLength);
    return 0;
}
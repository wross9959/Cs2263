#include <stdio.h>

void printArr(char a[], int n){

    for(int i = 0; i < n; i++){
        putchar(a[i]);
    }
    
}

int main(){
    char input[] = {"Enter chars, press enter when you want to stop\n"};
    
    putchar(input[]);
    for(int i = 0; input[i] != ' '; i++){
        printf("Input:");
        input[i] = getchar();
        printf("\n");
    }
    int arrayLength = sizeof(input)/ sizeof(input[0]);
    printArr(input, arrayLength);



    return 0;
}
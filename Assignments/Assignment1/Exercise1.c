#include <stdio.h>

void printArr(char a[], int n){
    //just a for loop to go through char array
    for(int i = 0; i < (n-1); i++){
        putchar(a[i]);
    } 

    //new line after complete
    putchar('\n');
}
int main(){
    char message[] = "Hello World";  
    char message2[] = "Will Ross";
    char message3[] = "3734692";
    char message4[] = "January 26th, 2024";  
    
    //test 1
    int arrayLength = sizeof(message)/ sizeof(message[0]);
    //printArr(message, arrayLength);

    //test 2
    int array2Length = sizeof(message2)/ sizeof(message2[0]);
    //printArr(message2, array2Length);
    
    //test 3
    int array3Length = sizeof(message3)/ sizeof(message3[0]);
    //printArr(message3, array3Length);

    //test 4
    int array4Length = sizeof(message4)/ sizeof(message4[0]);
    printArr(message4, array4Length);

    return 0;
}
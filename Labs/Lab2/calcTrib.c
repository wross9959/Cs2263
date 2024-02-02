#include <stdio.h>

int calcTrib(int n) {
    printf("value: %d memory address: %p\n", n, &n);
    return n;
}

int main(void){
    int numOfValues = 20, num1 = 0, num2 = 0, num3 = 1, num4 = 0;
    for(int i = 0; i < numOfValues; i++){
        if(i % 2 == 0){
            //printf("%d\n", num1);
            calcTrib(num1);
        }
        num4 = num1 + num2 + num3;
        num1 = num2;
        num2 = num3;
        num3 = num4;
    }
}
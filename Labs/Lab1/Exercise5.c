#include <stdio.h>

int main(){

    int numOfValues = 20, num1 = 0, num2 = 1, num3 = 2, num4 = 0;

    for(int i = 0; i < numOfValues; i++){
        if(i % 2 == 0){
            printf("%d\n", num1);
        }
        num4 = num1 + num2 + num3;
        num1 = num2;
        num2 = num3;
        num3 = num4;
    }

    return 0;
}
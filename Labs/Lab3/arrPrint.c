// arithmetic1.c
#include <stdio.h>
#include <stdlib.h>

void printArray(int arr[], int len){
    int *aptr = arr;
    printf("Index\tValue\tAddress\t\t\tValue\n");
    for(int i = 0; i < len; i++){
        printf("%d\t%d\t%p\t%d\n", i, arr[i], &arr[i], *aptr++);

    }
}

int arrindex(int a[], int * p){
    return p - a;
}


int main (int argc ,char * * argv)
{
    //for exercise 2
    int arr[] = {10, 11, 12, 13, 14, 15, 16};
    int len = sizeof(arr) / sizeof(int);
    printArray(arr, len);

    //for exercise 3
    // int arr[] = {10, 11, 12, 13, 14, 15, 16};
    // for (int i = 0; i < sizeof(arr)/sizeof(arr[0]); i ++){
    //     printf ("%d\t%p\n", i, arrindex( arr, & arr[i]));
    // }
    return EXIT_SUCCESS;
}
/*
 * wrongindex.c
 */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
int main(int argc, char * * argv)
{
    int x = -2;
    int arr[] = {0, 1, 2, 3, 4};
    int y = 15;

    //memory address of x and y
    //printf("& x = %p, & y = %p\n", (void*)& x, (void*)& y);

    printf("& of x = %p,\n& of y = %p\n", & x, & y);


    //one invaild
    printf("& of arr[%d] = %p\n", -1, (void *)&arr[-1]);

    //all valid
    for(int i = 0; i < sizeof(arr)/sizeof(arr[0]); i++){
        printf("& of arr[%d] = %p\n", i, (void *)&arr[i]);
    }
   

    printf("x = %d, y = %d\n", x, y);

    arr[-1] = 7;
    arr[5]  = -23;

    printf("x = %d, y = %d\n", x, y);


    arr[6]  = 108;

    printf("x = %d, y = %d\n", x, y);

    arr[7]  = -353;

    printf("x = %d, y = %d\n", x, y);

    return EXIT_SUCCESS;
}
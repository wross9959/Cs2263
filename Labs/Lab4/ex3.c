#include <stdio.h>
#include <stdlib.h>


void dummy_frame()
{
    return;
}

int main(int argc, char * * argv)
{

    int i;
    int size = 5;
    int addedSize = 8;
    int *a;
    
    //call malloc
    a = malloc(size * sizeof(int));

    printf("\nMalloc Values:\n\n");


    //fill array with 1 to 5
    for(i = 0; i < size; i++)
    {
        a[i] = i + 1;
    }

    //print the original array
    for (i=0; i< size; i++)
    {
        printf("a[%d] = %d at address: %p \n", i, a[i], &a[i]);
    }


    printf("\nRealloc Values:\n\n");

    //called realloc getting the orignal values + our new size
    int *b =  realloc(a, addedSize * sizeof(int));
    a = b;

    //add more values to the array
    for(i = size; i < addedSize; i++){
        a[i] = i + 1;
    }
    
    //print all values
    for (i=0; i< addedSize; i++)
    {
        printf("a[%d] = %d at address: %p \n", i, a[i], &a[i]);
    }
    free(a);
    return EXIT_SUCCESS;
}
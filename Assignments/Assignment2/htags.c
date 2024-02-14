#include <stdio.h>
#include <string.h>

int main()
{
    int c;
    char * ptr;

    while((c = getchar()) != EOF)
    {
        printf("%c\n", c);
        if((ptr = strchr((char *)&c, '<')) != NULL)
        {
            printf("The pointer = %c\n", *ptr);
        }
    }


    return 0;
}
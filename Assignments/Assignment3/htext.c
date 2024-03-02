#include <stdio.h>
#include <string.h>
#include <stdlib.h>
void readFile(char *filename)
{
    FILE *file = fopen(filename, "r");

    if (file == NULL)
    {
        printf("ERROR: Could not open file\n");
        return;
    }
    int currChar;
    while((currChar = fgetc(file)) != EOF)
    {
        if(currChar == '>')
        {
            while((currChar = fgetc(file)) != '<' && currChar != EOF)
            {
                printf("%c", currChar);
            }
            printf("%c",' ');
        }
    }
}


int main(int argc, char *argv[])
{
   
    if (argc != 2)
    {
        printf("ERROR: Provide a file to read.\n");
        return EXIT_FAILURE;
    }

    readFile(argv[1]);

    return EXIT_SUCCESS;

}

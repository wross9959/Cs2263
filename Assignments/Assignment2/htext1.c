#include <stdio.h>
#include <string.h>

void printArr(char a[], int n)
{
    //just a for loop to go through char array
    for(int i = 0; i < (n-1); i++)
    {

        putchar(a[i]);
    } 

    //new line after complete
    putchar('\n');
}

void readText()
{
    int currChar;
    int index = 0;
    int space = ' ';

    while((currChar = getchar()) != EOF)
    {
        if(currChar == '>')
        {
            while((currChar = getchar()) != '<' && currChar != EOF)
            {
                putchar(currChar);
            }
            putchar(space);
        }
    }
}
int main() 
{
    char start[] = "Start of output:";


    printArr(start, strlen(start));
    readText();


    return 0;
}



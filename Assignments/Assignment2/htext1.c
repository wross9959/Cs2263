#include <stdio.h>
#include <string.h>

void printArr(char a[], int n){
    //just a for loop to go through char array
    for(int i = 0; i < (n-1); i++){

        putchar(a[i]);
    } 

    //new line after complete
    putchar('\n');
}
void rem(char a[], int n){
    int indexArray[n];
    int index = 0;
    for(int i = 0; i < (n-1); i++)
    {
        if(a[i] != '\n')
        {
            indexArray[index] = i;
            index++;
        }
    }
    char newString[index];
    for(int i = 0; i < (index -1); i++){
        newString[i] = a[indexArray[i]];
    }
    printArr(newString, strlen(newString));
}
void readText()
{
    int textLength = 1316134;
    char text[textLength];
    int currChar;
    int index = 0;
    int space = ' ';
    int newline = '\n';

    while((currChar = getchar()) != EOF)
    {
        if(currChar == '>')
        {
            while((currChar = getchar()) != '<' && currChar != EOF){
                putchar(currChar);
                //text[index++] = currChar;
            }
            //text[index++] = ' ';
            putchar(space);
        }
    }
    //text[index++] = '\0';
    //rem(text, strlen(text));
}
int main() 
{
    readText();
    return 0;
}



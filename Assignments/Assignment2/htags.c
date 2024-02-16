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
void readTags()
{
    //int tagsLength = 1316134;
    //char tags[tagsLength];
    int currChar;
    int first = '<';
    int second = '>';
    int space = ' ';
    int newline = '\n';
    //int index = 0;

    while((currChar = getchar()) != EOF)
    {
        if(currChar == '<')
        {
            //tags[index++] = '<';
            putchar(first);
            while((currChar = getchar()) != '>' && currChar != EOF){
                //tags[index++] = currChar;
                putchar(currChar);
            }
            putchar(second);
            putchar(newline);
            //tags[index++] = '>';
            //tags[index++] = '\n';
        }
    }
    //tags[index++] = '\0';
    //printArr(tags, strlen(tags));
}
int main() 
{
    readTags();
    return 0;
}



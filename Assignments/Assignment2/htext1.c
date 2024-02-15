#include <stdio.h>

void printArr(char a[], int n){
    //just a for loop to go through char array
    for(int i = 0; i < (n-1); i++){

        putchar(a[i]);
    } 

    //new line after complete
    putchar('\n');
}
void removeWhiteSpace(char a[], int n)
{
    int indexArray[1000];
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
        if(a[indexArray[i]] == '<')
        {
            i++;
            if(a[indexArray[i]] == 'b')
            {
                i++;

                if(a[indexArray[i]] == '/')
                {
                    newString[i] = ' ';
                    i++;
                }
                else{
                    newString[i] = ' ';
                }
            }
        }
        else if(a[indexArray[i]] == 'b'){
            i++;
            if(a[indexArray[i]] == '>'){
            
            }
        }
        else{
            newString[i] = a[indexArray[i]];
        }
        
    }
    printArr(newString, index);
}

void readFile()
{
    int textLength = 1000;
    char text[textLength];
    char currChar;
    int inTag = 0; 
    int inComment = 0; 
    int index = 0;

    while ((currChar = getchar()) != EOF ) 
    {
        if (!inComment && currChar == '<') 
        {
            if ((currChar = getchar()) == '!') 
            { 
                if ((currChar = getchar()) == '-' && (currChar = getchar()) == '-') 
                {
                    inComment = 1; 
                    continue;
                }
            } 
            else 
            {
                inTag = 1; 
            }
        } 
        else if (inComment && currChar == '-' && (currChar = getchar()) == '-' && (currChar = getchar()) == '>') 
        {
            inComment = 0; 
            continue;
        } 
        else if (inTag && currChar == '>') 
        {
            inTag = 0; 
            text[index++] = getchar();
            continue;
        }

        if (!inTag && !inComment ) 
        {
            text[index++] = currChar; 
        }
    }
    text[index] = '\0';
    removeWhiteSpace(text,index);
}


int main() 
{
    readFile();
    return 0;
}



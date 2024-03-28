#include <stdio.h>
#include <string.h>
#include <stdbool.h>
void printArr(char a[], int n){

    for(int i = 0; i < (n-1); i++){

        putchar(a[i]);
    } 

    putchar('\n');
}
void readTags()
{

    int currChar;
    int first = '<';
    int second = '>';
    int newline = '\n';
    bool inComment = false;
    int check;

    while((currChar = getchar()) != EOF)
    {
        inComment = false;
        if(currChar == '<')
        {
            
            check = getchar();
            // check = getchar();
            if(check == '!' )
            {
                
                inComment = true;
            }
            else
            {
                putchar(first);
                putchar(check);
                
            }

            while((currChar = getchar()) != '>' && currChar != EOF){
                if(!inComment)
                {
                    putchar(currChar);
                    continue;
                }
            }
            if(!inComment)
            {
                
                putchar(second);
                putchar(newline);
                
            }
            
 
        }
        
    }

}
int main() 
{

    char start[] = "Start of output:\n";
    char end[] = "End of output:\n";

    printArr(start, strlen(start));
    readTags();
    printArr(end, strlen(end));
    
    return 0;
}



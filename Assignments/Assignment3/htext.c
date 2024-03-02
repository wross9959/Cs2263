#include <stdio.h>
#include <string.h>

void readText2(char input[])
{
    
    for(int i = 0; i != '\0'; i++)
    {
        printf("Works");
        if(input[i] == '>') 
        {
            
            while(i != '<' && i != '\0')
            {
                i++;
                printf(&input[i]);
            }
            printf(" ");
        }
    }
}
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

int main(int argc, char *argv[])
{
    char input[100];
    //printf("Provide some htags for the program:\n");
    //scanf("%s", &input);
    //printf("%s", input);
    //printArr(input, strlen(input));

    FILE *file = fopen(argv[1], "r");
    if (!file) {
        perror("Error opening file");
        return 1;
    }
    
    FILE *pF = fopen("C:\\Users\\willr\\Documents\\GitHub\\Cs2263\\Assignments\\Assignment3\\index.html", "r");
    char buffer[255];

    while(fgets(buffer, 255, pF) != NULL)
    {
        printf("%s", buffer);
    }
    // fgets(buffer, 255, pF);
    
    fclose(pF);

    return 0;

}

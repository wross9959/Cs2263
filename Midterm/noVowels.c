#include <stdio.h>
#include <string.h>

void printArr(char a[], int n)
{
    int i;

    for (i = 0; i < n; i++)
    {
        putchar(a[i]);
    }
    putchar('\n');
}
void noVowels(char s[])
{
    char result[100];
    char vowels[] = {'a', 'e', 'i', 'o', 'u'};
    int index = 0;

    for(int i = 0; s[i] != '\0'; i++){
        for(int j = 0; vowels[j] != '\0'; j++){

            if(s[i] != vowels[j]){

                result[index++] = s[i];
                break;
            }
            else{

                break;
            }
        }
    }
    printArr(result, index);
}
int main()
{
    char test1[] = "abra cadabra";

    noVowels(test1);
    return 0;
}
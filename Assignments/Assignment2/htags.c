#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_TAG_LENGTH 1000

void extract_tags() {
    int c;
    while ((c = getchar()) != EOF) {
        if (c == '<') {
            putchar(c);
            while ((c = getchar()) != EOF && c != '>') {
                putchar(c);
            }
            if (c != EOF) {
                putchar(c);
            }
        }
    while ((c = getchar()) != EOF) {
        if (c == '<') {
            // Skip past the tag
            while ((c = getchar()) != EOF && c != '>') {
                // Ignore characters within the tag
            }
        } else {
            // Print the plain text character
            putchar(c);
        }
    }
}

int main()
{
    // Uncomment the appropriate function call based on the utility program you want to run
    // extract_tags();
    // extract_plain_text();
    printf("\n");
    return 0;
}


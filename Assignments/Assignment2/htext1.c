#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main() {
    char ch;
    int inTag = 0;
    int inComment = 0;

    while ((ch = getchar()) != EOF) {
        if (ch == '<') {
            inTag = 1;
            // Check for the start of a comment
            if ((ch = getchar()) == '!' && (ch = getchar()) == '-' && (ch = getchar()) == '-') {
                inComment = 1;
                inTag = 0;
            }
        } else if (inComment && ch == '-') {
            if ((ch = getchar()) == '-' && (ch = getchar()) == '>') {
                inComment = 0;
            }
        } else if (ch == '>') {
            inTag = 0;
        } else if ((inTag == 0) && (inComment == 0)) {
            //putchar(ch);
        }
    }

    return 0;
}

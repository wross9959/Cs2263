#include <stdio.h>

int calcTrib(int n) {
    if (n == 0) return 0;
    if (n == 1 || n == 2) return 1;

    int a = 0, b = 1, c = 1, d;
    for (int i = 3; i <= n; i++) {
        d = a + b + c;
        a = b;
        b = c;
        c = d;
    }
    return c;
}

int main() {
    for (int i = 0; i < 10; i += 2) {
        printf("%d ", calcTrib(i));
    }
    printf("\n");
    return 0;
}

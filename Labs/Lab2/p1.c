/* p1.c */
#include <stdio.h>
#include <stdlib.h>
int g1(int a, int b)
{
    int c = (a + b) * b;
    printf("g1:   a = %d, b = %d, c = %d\n", a, b, c);
    printf("g1: address of a = %p, address of b = %p, address of c = %p\n", (void *)&a, (void *)&b, (void *)&c);
    return c;
}

int g2(int a, int b)
{
    int c = g1(a + 3, b - 11);
    printf("g2:   a = %d, b = %d, c = %d\n", a, b, c);
    printf("g2: address of a = %p, address of b = %p, address of c = %p\n", (void *)&a, (void *)&b, (void *)&c);
    return c - b;
}

int main(int argc, char * * argv)
{
    int a = 5;
    int b = 17;
    int c = g2(a - 1, b * 2);
    printf("main: a = %d, b = %d, c = %d\n", a, b, c);
    printf("main: address of a = %p, address of b = %p, address of c = %p\n", (void *)&a, (void *)&b, (void *)&c);
    return EXIT_SUCCESS;
}
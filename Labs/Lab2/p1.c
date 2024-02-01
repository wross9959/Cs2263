/* p1.c */
#include <stdio.h>
#include <stdlib.h>
int g1(int a, int b)
{
    int c = (a + b) * b;
    printf("g1:\na = %d\nb = %d\nc = %d\n", a, b, c);
    printf("g1:\naddress of a = %p\naddress of b = %p\naddress of c = %p\n", &a, &b, &c);
    return c;
}

int g2(int a, int b)
{
    int c = g1(a + 3, b - 11);
    printf("g2:\na = %d\nb = %d\nc = %d\n", a, b, c);
    printf("g2:\naddress of a = %p\naddress of b = %p\naddress of c = %p\n",&a,&b,&c);
    return c - b;
}

int main(int argc, char * * argv)
{
    int a = 5;
    int b = 17;
    int c = g2(a - 1, b * 2);
    printf("main:\na = %d\nb = %d\nc = %d\n", a, b, c);
    printf("main:\naddress of a = %p\naddress of b = %p\naddress of c = %p\n", &a,&b,&c);
    return EXIT_SUCCESS;
}
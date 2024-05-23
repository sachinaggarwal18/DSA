#include <stdio.h>

int fib(int n)
{
    if (n < 2)
        return n; // 0 or 1

    return fib(n - 1) + fib(n - 2);
}

int main()
{
    int n;
    printf("enter value of n:");
    scanf("%d", &n);
    printf("%d", fib(n));

    return 0;
}
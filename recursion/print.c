#include <stdio.h>

void printNum(int num, int n)
{
    if (num > n)
        return;

    printf("%d\n", num);
    printNum(num + 1, n);
}

void printNumRev(int num, int n)
{
    if (num == 0)
        return;

    printf("%d\n", num);
    printNumRev(num - 1, n);
}

int main()
{
    int n = 5;
    printNum(1, 10);
    printNumRev(10, 1);
    return 0;
}
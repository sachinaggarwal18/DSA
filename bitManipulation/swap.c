#include <stdio.h>

int main()
{

    int a, b;

    printf("Enter a, b: ");

    scanf("%d %d", &a, &b);
    printf("Original a = %d, b = %d\n", a, b);
    a = a ^ b;
    b = a ^ b;
    a = a ^ b;

    printf("Swapped a = %d, b = %d\n", a, b);

    return 0;
}

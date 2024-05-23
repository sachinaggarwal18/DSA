// #include <stdio.h>
// #include <limits.h>

// int max(int a, int b)
// {
//     return a > b ? a : b;
// }

// int largest(int arr, int n, int ind)
// {
//     if (ind == n)
//         return INT_MIN;
//     return max(arr[ind], largest(arr, n, ind + 1));
// }

// int main()
// {
//     int arr[] = {3, 4, -3, -6, 11, 3};
//     int n = sizeof(arr) / sizeof(int);
//     printf("%d", max(arr, n));
//     return 0;
// }
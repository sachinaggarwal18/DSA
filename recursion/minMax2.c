#include <stdio.h>
#include <limits.h>

// int max(int arr[], int i)
// {
//     int largest = INT_MIN;

//     if (arr[i] > largest)
//         largest = arr[i];

//     return max(arr[i], i + 1);
// }

int max(int arr[], int n)
{
    if (n == 0)
        return arr[0];

    if (arr[n] > max(arr, n + 1))
    {
        return arr[n];
    }
    else
        return max(arr, n + 1);
}
int min(int arr[], int i)
{
    int smallest = INT_MIN;

    if (arr[i] < smallest)
        smallest = arr[i];

    return max(arr[i], i + 1);
}

int main()
{
    int n = 5;
    int arr[] = {3, 2, 7, 6, -1};

    printf("%d", max(arr, 4));
}
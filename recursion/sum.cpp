#include <iostream>
using namespace std;

int sumArr(int *arr, int size)
{
    if (size == 0)
    {
        return 0;
    }

    if (size == 1)
    {
        return arr[0];
    }

    int remaining = sumArr(arr + 1, size - 1);
    int sum = arr[0] + remaining;
}

int main()
{
    int arr[] = {1, 2, 3, 4, 5, 6, 7, 8};
    int size = 8;

    int sum = sumArr(arr, size);

    cout << sum;

    return 0;
}

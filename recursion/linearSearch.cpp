#include <string.h>
#include <iostream>
using namespace std;

bool search(int arr[], int size, int k)
{
    if (size == 0)
        return false;

    if (arr[0] == k)
    {
        return true;
    }
    else
    {
        bool remaining = search(arr + 1, size - 1, k);
    }
}

int main()
{
    int arr[] = {2, 4, 6, 11, 3, 3, 5, 6, 67, 657, 7, 90};
    int size = 12;

    int k = 657;

    bool ans = search(arr, size, k);
    if (ans)
    {
        cout << "present ";
    }
    else
    {
        cout << "not present";
    }
}
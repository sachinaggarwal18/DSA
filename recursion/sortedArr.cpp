#include <iostream>
using namespace std;

bool isSorted(int *arr, int size)
{
    if (size == 0 || size == 1)
    {
        return true;
    }
    if (arr[0] > arr[1])
    {
        return false;
    }
    else
    {
        bool ans = isSorted(arr + 1, size - 1);
        return ans; // Return the value calculated in recursive call
    }
}

int main()
{
    int arr[] = {1, 2, 3, 4, 5, 6, 7, 8};
    int size = 8;

    bool ans = isSorted(arr, size);

    if (ans)
    {
        cout << "Array is sorted." << endl;
    }
    else
    {
        cout << "Array is not sorted." << endl;
    }

    return 0;
}

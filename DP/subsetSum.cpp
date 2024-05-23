#include <iostream>
#include <vector> // Include the vector header
using namespace std;

bool solve(int arr[], int n, int target)
{
    if (target == 0)
        return true;
    if (n == 0)
        return false;

    bool flag = false;
    if (arr[n - 1] <= target)
    {
        bool pick = solve(arr, target - arr[n - 1], n - 1);

        if (pick)
            return pick;

        bool notPick = solve(arr, target, n - 1);
        return notPick;
    }

    return flag;
}

int subsetsum(int arr[], int n, int target)
{
    if (target == 0)
        return 1;
    if (n == 0)
        return 0;

    if (arr[n - 1] <= target)
    {
        int pick = subsetsum(arr, target - arr[n - 1], n - 1);
        int notPick = subsetsum(arr, target, n - 1);

        return pick + notPick;
    }
    else
    {
        subsetsum(arr, target, n - 1);
    }
}

bool canPartition(int arr[], int n)
{
    int totalSum = 0;
    for (int i = 0; i < n; i++)
    {
        totalSum += arr[i];
    }

    if (totalSum % 2 != 0)
        return false;

    int halfSum = totalSum / 2;

    return solve(arr, n, halfSum);
}

int main()
{
    int arr[] = {1, 3, 2, 5, 4, 6};

    int ans = subsetsum(arr, 6, 10);
    cout << ans;
}
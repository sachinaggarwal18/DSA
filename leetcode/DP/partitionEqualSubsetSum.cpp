#include <iostream>
#include <vector>
using namespace std;

class Solution
{
public:
    bool solve(int ind, vector<int> &arr, int n, int target, vector<vector<int>> &dp)
    {

        if (target == 0)
            return true;
        if (target < 0 || ind < 0)
            return false;

        if (dp[ind][target] != -1)
        {
            return dp[ind][target];
        }

        bool take = false;
        if (arr[ind] <= target)
        {
            take = solve(ind - 1, arr, n, target - arr[ind], dp);
        }

        bool notTake = solve(ind - 1, arr, n, target, dp);

        return dp[ind][target] = take || notTake;
    }

    bool canPartition(vector<int> &arr, int n)
    {
        int totalSum = 0;
        for (int i = 0; i < n; i++)
        {
            totalSum += arr[i];
        }

        if (totalSum % 2 != 0)
        {
            return false;
        }

        int halfSum = totalSum / 2;
        vector<vector<int>> dp(n, vector<int>(halfSum + 1, -1));

        return solve(n - 1, arr, n, halfSum, dp);
    }
};

int main()
{
    Solution obj;
    int n;
    cout << "Enter number of elements: ";
    cin >> n;

    vector<int> arr(n);
    cout << "Enter elements: ";

    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }

    if (obj.canPartition(arr, n))
    {
        cout << "The array can be partitioned into two subsets with equal sum." << endl;
    }
    else
    {
        cout << "The array cannot be partitioned into two subsets with equal sum." << endl;
    }
    return 0;
}
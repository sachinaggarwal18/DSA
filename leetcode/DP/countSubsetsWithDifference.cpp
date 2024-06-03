#include <iostream>
#include <vector>
using namespace std;

int mod = (int)(1e9 + 7);
int f(int i, int sum, vector<int> &arr, vector<vector<int>> &dp)
{

    if (i == 0)
    {
        if (sum == 0 && arr[0] == 0)
        {
            return 2;
        }

        if (sum == 0 || sum == arr[0])
        {
            return 1;
        }
        return 0;
    }

    if (dp[i][sum] != -1)
    {
        return dp[i][sum];
    }

    int take = 0;
    if (arr[i] <= sum)
    {
        take = f(i - 1, sum - arr[i], arr, dp);
    }

    int notTake = f(i - 1, sum, arr, dp);

    return dp[i][sum] = (take + notTake) % mod;
}
int findWays(vector<int> &arr, int sum)
{
    int n = arr.size();

    vector<vector<int>> dp(n, vector<int>(sum + 1, -1));
    return f(n - 1, sum, arr, dp);
}

int countPartitions(int n, int d, vector<int> &arr)
{
    // Write your code here.
    int totalSum = 0;

    for (auto &it : arr)
    {
        totalSum += it;
    }

    if (totalSum - d < 0 || (totalSum - d) % 2 != 0)
        return false;

    return findWays(arr, (totalSum - d) / 2);
}

int main()
{

    int n, d;
    cout << "Enter the no. of elements: ";
    cin >> n;

    vector<int> arr(n);
    cout << "Enter the elements: ";
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }

    cout << "Enter the value of d: ";
    cin >> d;

    int ans = countPartitions(n, d, arr);
    cout << "Ans: " << ans;
}
#include <iostream>
#include <vector>
using namespace std;
const int MOD = 1e9 + 7;

class Solution
{
public:
    int f(int i, vector<int> &arr, int target, vector<vector<int>> &dp)
    {

        if (target == 0)
            return 1;

        if (target < 0 || i < 0)
            return 0;

        if (dp[i][target] != -1)
        {
            return dp[i][target];
        }
        int take = 0;
        if (arr[i] <= target)
        {
            take = f(i - 1, arr, target - arr[i], dp);
        }

        int notTake = f(i - 1, arr, target, dp);

        return dp[i][target] = (take + notTake) % MOD;
    }
    int findWays(vector<int> &arr, int k)
    {
        // Write your code here.
        int n = arr.size();

        vector<vector<int>> dp(n, vector<int>(k + 1, -1));
        return f(n - 1, arr, k, dp);
    }
};

int main()
{
    Solution obj;
    int n, k;
    cout << "Enter number of elements: ";
    cin >> n;

    vector<int> arr(n);
    cout << "Enter elements: ";
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }

    cout << "Enter target: ";
    cin >> k;

    int result = obj.findWays(arr, k);
    cout << "Number of ways to achieve the target sum: " << result << endl;

    return 0;
}
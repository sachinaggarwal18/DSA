#include <iostream>
#include <vector>
using namespace std;

const int MOD = 1e9 + 7;
class Solution
{
public:
    int findWays(vector<int> &arr, int k)
    {
        // Write your code here.
        int n = arr.size();
        int ans;
        vector<vector<int>> dp(n + 1, vector<int>(k + 1, 0));

        for (int i = 0; i <= n; i++)
        {
            dp[i][0] = 1;
        }

        for (int i = 1; i <= n; i++)
        {
            for (int j = 1; j <= k; j++)
            {
                dp[i][j] = dp[i - 1][j]; // notpick
                if (arr[i - 1] <= j)
                {

                    dp[i][j] += (dp[i - 1][j - arr[i - 1]]) % MOD; // pick
                }
            }
        }

        return dp[n][k];
    }
};

int main()
{
    Solution obj;
    int n, k;
    cout << "Enter no. of elements: " << endl;
    cin >> n;

    vector<int> arr(n);
    cout << "Enter elements: " << endl;

    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }
    cout << "Enter the target: " << endl;
    cin >> k;

    int result = obj.findWays(arr, k);
    cout << "No. of subsets: " << result << endl;
}
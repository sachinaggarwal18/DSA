#include <iostream>
#include <vector>
using namespace std;

class Solution
{
public:
    bool subsetSumToK(int n, int k, vector<int> &arr)
    {
        vector<vector<bool>> dp(n + 1, vector<bool>(k + 1, 0));

        // Base case: A subset with sum 0 is always possible (empty subset)
        for (int i = 0; i <= n; ++i)
        {
            dp[i][0] = true;
        }

        for (int i = 1; i <= n; ++i)
        {
            for (int j = 1; j <= k; ++j)
            {
                if (arr[i - 1] <= j)
                {
                    // Either include the current element or exclude it
                    dp[i][j] = dp[i - 1][j] || dp[i - 1][j - arr[i - 1]];
                }
                else
                {
                    // Exclude the current element
                    dp[i][j] = dp[i - 1][j];
                }
            }
        }

        // The answer will be in dp[n][k]
        return dp[n - 1][k];
    }
};

int main()
{
    Solution obj;
    int n, k;
    cout << "Enter number of elements: " << endl;
    cin >> n;

    vector<int> arr(n);
    cout << "Enter elements: " << endl;

    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }
    cout << "Enter target: " << endl;
    cin >> k;

    if (obj.subsetSumToK(n, k, arr))
    {
        cout << "Subset with sum " << k << " exists." << endl;
    }
    else
    {
        cout << "Subset with sum " << k << " does not exists." << endl;
    }
    return 0;
}
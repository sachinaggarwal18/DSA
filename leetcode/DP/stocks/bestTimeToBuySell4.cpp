#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class Solution
{
public:
    int solve(int ind, int k, int flag, vector<int> &arr,
              vector<vector<vector<int>>> &dp)
    {
        // 1->allowed to buy
        // 0->not allowed to buy

        int n = arr.size();
        if (ind >= n || k == 0)
        {
            return 0;
        }

        if (dp[ind][k][flag] != -1)
        {
            return dp[ind][k][flag];
        }

        int profit = 0;
        if (flag)
        {
            int buy = -arr[ind] + solve(ind + 1, k, 0, arr, dp);
            int notBuy = 0 + solve(ind + 1, k, 1, arr, dp);
            profit = max(buy, notBuy);
        }
        else
        {
            int notSell = 0 + solve(ind + 1, k, 0, arr, dp);
            int sell = arr[ind] + solve(ind + 1, k - 1, 1, arr, dp);
            profit = max(notSell, sell);
        }

        return dp[ind][k][flag] = profit;
    }

    int maxProfit(int k, vector<int> &prices)
    {
        int n = prices.size();
        vector<vector<vector<int>>> dp(n, vector<vector<int>>(k + 1, vector<int>(2, -1)));
        return solve(0, k, 1, prices, dp);
    }
};

int main()
{
    int k, n;
    cout << "Enter the number of transactions (k): ";
    cin >> k;
    cout << "Enter the number of days (length of prices array): ";
    cin >> n;

    vector<int> prices(n);
    cout << "Enter the prices: ";
    for (int i = 0; i < n; i++)
    {
        cin >> prices[i];
    }

    Solution sol;
    int maxProfit = sol.maxProfit(k, prices);
    cout << "Maximum profit with " << k << " transactions is: " << maxProfit << endl;

    return 0;
}

#include <iostream>
#include <vector>
#include <climits>
#include <algorithm>
using namespace std;

class Solution
{
public:
    int recursion(int ind, int flag, int count, vector<int> &arr)
    {
        int n = arr.size();
        if (ind >= n || count == 0)
        {
            return 0;
        }

        int profit = INT_MIN;

        if (flag)
        {
            int buy = -arr[ind] + recursion(ind + 1, 0, count, arr);
            int notBuy = 0 + recursion(ind + 1, 1, count, arr);
            profit = max(buy, notBuy);
        }
        else
        {
            int sell = arr[ind] + recursion(ind + 1, 1, count - 1, arr);
            int notSell = 0 + recursion(ind + 1, 0, count, arr);
            profit = max(sell, notSell);
        }
        return profit;
    }

    int memoization(int ind, int flag, int count, vector<int> &arr, vector<vector<vector<int>>> &dp)
    {
        int n = arr.size();
        if (ind >= n || count == 0)
        {
            return 0;
        }

        if (dp[ind][flag][count] != -1)
        {
            return dp[ind][flag][count];
        }

        int profit = INT_MIN;

        if (flag)
        {
            int buy = -arr[ind] + memoization(ind + 1, 0, count, arr, dp);
            int notBuy = 0 + memoization(ind + 1, 1, count, arr, dp);
            profit = max(buy, notBuy);
        }
        else
        {
            int sell = arr[ind] + memoization(ind + 1, 1, count - 1, arr, dp);
            int notSell = 0 + memoization(ind + 1, 0, count, arr, dp);
            profit = max(sell, notSell);
        }
        return dp[ind][flag][count] = profit;
    }

    int tabulation(vector<int> &arr, vector<vector<vector<int>>> &tabDp)
    {
        int n = arr.size();

        for (int i = n - 1; i >= 0; i--)
        {
            for (int j = 0; j <= 1; j++)
            {
                for (int k = 1; k <= 2; k++)
                {
                    int profit = INT_MIN;
                    if (j)
                    {
                        int buy = -arr[i] + tabDp[i + 1][0][k];
                        int notBuy = tabDp[i + 1][1][k];
                        profit = max(buy, notBuy);
                    }
                    else if (k > 0)
                    {
                        int sell = arr[i] + tabDp[i + 1][1][k - 1];
                        int notSell = tabDp[i + 1][0][k];
                        profit = max(sell, notSell);
                    }
                    tabDp[i][j][k] = profit;
                }
            }
        }

        return tabDp[0][1][2];
    }

    int maxProfitRecursion(vector<int> &prices)
    {
        return recursion(0, 1, 2, prices);
    }

    int maxProfitMemoization(vector<int> &prices)
    {
        int n = prices.size();
        vector<vector<vector<int>>> dp(n, vector<vector<int>>(2, vector<int>(3, -1)));
        return memoization(0, 1, 2, prices, dp);
    }

    int maxProfitTabulation(vector<int> &prices)
    {
        int n = prices.size();
        vector<vector<vector<int>>> tabDp(n + 1, vector<vector<int>>(2, vector<int>(3, 0)));
        return tabulation(prices, tabDp);
    }
};

int main()
{
    Solution sol;
    int n;
    cout << "Enter number of days: ";
    cin >> n;
    vector<int> prices(n);
    cout << "Enter prices: ";
    for (int i = 0; i < n; i++)
    {
        cin >> prices[i];
    }

    cout << "Max Profit (Recursion): " << sol.maxProfitRecursion(prices) << endl;
    cout << "Max Profit (Memoization): " << sol.maxProfitMemoization(prices) << endl;
    cout << "Max Profit (Tabulation): " << sol.maxProfitTabulation(prices) << endl;

    return 0;
}

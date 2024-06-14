#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class Solution
{
public:
    // Recursive solution
    int solveRecursive(int ind, int flag, vector<int> &arr)
    {
        int n = arr.size();
        if (ind >= n)
        {
            return 0;
        }

        int profit = 0;
        if (flag)
        {
            int buy = -arr[ind] + solveRecursive(ind + 1, 0, arr);
            int notBuy = 0 + solveRecursive(ind + 1, 1, arr);
            profit = max(buy, notBuy);
        }
        else
        {
            int notSell = 0 + solveRecursive(ind + 1, 0, arr);
            int sell = arr[ind] + solveRecursive(ind + 2, 1, arr);
            profit = max(notSell, sell);
        }

        return profit;
    }

    // Memoization solution
    int solveMemo(int ind, int flag, vector<int> &arr, vector<vector<int>> &dp)
    {
        int n = arr.size();
        if (ind >= n)
        {
            return 0;
        }

        if (dp[ind][flag] != -1)
        {
            return dp[ind][flag];
        }

        int profit = 0;
        if (flag)
        {
            int buy = -arr[ind] + solveMemo(ind + 1, 0, arr, dp);
            int notBuy = 0 + solveMemo(ind + 1, 1, arr, dp);
            profit = max(buy, notBuy);
        }
        else
        {
            int notSell = 0 + solveMemo(ind + 1, 0, arr, dp);
            int sell = arr[ind] + solveMemo(ind + 2, 1, arr, dp);
            profit = max(notSell, sell);
        }

        return dp[ind][flag] = profit;
    }

    // Tabulation solution
    int tabulation(vector<int> &arr, vector<vector<int>> &tabDp)
    {
        int n = arr.size();
        for (int i = n - 1; i >= 0; i--)
        {
            for (int j = 0; j <= 1; j++)
            {
                if (j == 1)
                {
                    tabDp[i][j] =
                        max(-arr[i] + tabDp[i + 1][0], tabDp[i + 1][1]);
                }
                else
                {
                    int sell = arr[i] + (i + 2 < n ? tabDp[i + 2][1] : 0);
                    tabDp[i][j] = max(sell, tabDp[i + 1][0]);
                }
            }
        }
        return tabDp[0][1];
    }

    int maxProfitRecursive(vector<int> &prices)
    {
        return solveRecursive(0, 1, prices);
    }

    int maxProfitMemo(vector<int> &prices)
    {
        int n = prices.size();
        vector<vector<int>> dp(n + 1, vector<int>(2, -1));
        return solveMemo(0, 1, prices, dp);
    }

    int maxProfitTabulation(vector<int> &prices)
    {
        int n = prices.size();
        vector<vector<int>> tabDp(n + 1, vector<int>(2, 0));
        return tabulation(prices, tabDp);
    }
};

int main()
{
    int n;
    cout << "Enter the number of days (length of prices array): ";
    cin >> n;

    vector<int> prices(n);
    cout << "Enter the prices: ";
    for (int i = 0; i < n; i++)
    {
        cin >> prices[i];
    }

    Solution sol;
    int maxProfitRec = sol.maxProfitRecursive(prices);
    int maxProfitMemo = sol.maxProfitMemo(prices);
    int maxProfitTab = sol.maxProfitTabulation(prices);

    cout << "Maximum profit using recursion is: " << maxProfitRec << endl;
    cout << "Maximum profit using memoization is: " << maxProfitMemo << endl;
    cout << "Maximum profit using tabulation is: " << maxProfitTab << endl;

    return 0;
}

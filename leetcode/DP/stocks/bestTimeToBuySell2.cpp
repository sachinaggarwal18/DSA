#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class Solution
{
public:
    int solve(int ind, int flag, vector<int> &arr, vector<vector<int>> &dp)
    {
        // 1->allowed to buy
        // 0->not allowed to buy

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
            int buy = -arr[ind] + solve(ind + 1, 0, arr, dp);
            int notBuy = 0 + solve(ind + 1, 1, arr, dp);
            profit = max(buy, notBuy);
        }
        else
        {
            int notSell = 0 + solve(ind + 1, 0, arr, dp);
            int sell = arr[ind] + solve(ind + 1, 1, arr, dp);
            profit = max(notSell, sell);
        }

        return dp[ind][flag] = profit;
    }

    int tabulation(int ind, int flag, vector<int> &arr, vector<vector<int>> &tabDp)
    {
        int n = arr.size();
        tabDp[n][0] = tabDp[n][1] = 0;

        for (int i = n - 1; i >= 0; i--)
        {
            for (int j = 0; j <= 1; j++)
            {
                int profit = 0;
                if (j)
                {
                    int buy = -arr[i] + tabDp[i + 1][0];
                    int notBuy = 0 + tabDp[i + 1][1];
                    profit = max(buy, notBuy);
                }
                else
                {
                    int notSell = 0 + tabDp[i + 1][0];
                    int sell = arr[i] + tabDp[i + 1][1];
                    profit = max(notSell, sell);
                }

                tabDp[i][j] = profit;
            }
        }
        return tabDp[0][1];
    }

    int spaceOpti(int ind, int flag, vector<int> &arr)
    {
        int n = arr.size();
        vector<int> prev(2, 0), curr(2, 0);

        for (int i = n - 1; i >= 0; i--)
        {
            for (int j = 0; j <= 1; j++)
            {
                int profit = 0;
                if (j)
                {
                    int buy = -arr[i] + prev[0];
                    int notBuy = 0 + prev[1];
                    profit = max(buy, notBuy);
                }
                else
                {
                    int notSell = 0 + prev[0];
                    int sell = arr[i] + prev[1];
                    profit = max(notSell, sell);
                }

                curr[j] = profit;
            }
            prev = curr;
        }
        return prev[1];
    }

    int maxProfit(vector<int> &prices)
    {
        int n = prices.size();
        vector<vector<int>> dp(n + 1, vector<int>(2, -1));
        vector<vector<int>> tabDp(n + 1, vector<int>(2, 0));
        // return solve(0, 1, prices, dp);
        // return tabulation(0, 1, prices, tabDp);
        return spaceOpti(0, 1, prices);
    }
};

int main()
{
    vector<int> prices;
    int n, price;

    cout << "Enter the number of days: ";
    cin >> n;

    cout << "Enter the prices: ";
    for (int i = 0; i < n; i++)
    {
        cin >> price;
        prices.push_back(price);
    }

    Solution sol;
    int result = sol.maxProfit(prices);
    cout << "Maximum profit: " << result << endl;

    return 0;
}

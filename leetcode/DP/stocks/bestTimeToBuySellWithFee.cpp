#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class Solution
{
public:
    int maxProfit(vector<int> &prices, int fee)
    {
        int n = prices.size();
        vector<vector<int>> tabDp(n + 1, vector<int>(2, 0));

        tabDp[n][0] = tabDp[n][1] = 0;

        for (int i = n - 1; i >= 0; i--)
        {
            for (int j = 0; j <= 1; j++)
            {
                int profit = 0;
                if (j)
                {
                    int buy = -prices[i] + tabDp[i + 1][0];
                    int notBuy = 0 + tabDp[i + 1][1];
                    profit = max(buy, notBuy);
                }
                else
                {
                    int notSell = 0 + tabDp[i + 1][0];
                    int sell = prices[i] - fee + tabDp[i + 1][1];
                    profit = max(notSell, sell);
                }
                tabDp[i][j] = profit;
            }
        }
        return tabDp[0][1];
    }
};

int main()
{
    int n, fee;
    cout << "Enter the number of days (length of prices array): ";
    cin >> n;

    vector<int> prices(n);
    cout << "Enter the prices: ";
    for (int i = 0; i < n; i++)
    {
        cin >> prices[i];
    }

    cout << "Enter the transaction fee: ";
    cin >> fee;

    Solution sol;
    int maxProfit = sol.maxProfit(prices, fee);

    cout << "Maximum profit with transaction fee is: " << maxProfit << endl;

    return 0;
}

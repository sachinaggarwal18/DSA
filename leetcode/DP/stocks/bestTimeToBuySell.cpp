#include <iostream>
#include <vector>
using namespace std;

class Solution
{
public:
    int maxProfit(vector<int> &prices)
    {
        int profit = 0;
        int mini = prices[0];
        int n = prices.size();

        for (int i = 1; i < n; i++)
        {
            int cost = prices[i] - mini;
            profit = max(profit, cost);
            mini = min(mini, prices[i]);
        }

        return profit;
    }
};

int main()
{
    int n;
    cout << "Enter the number of days: ";
    cin >> n;

    vector<int> prices(n);
    cout << "Enter the prices: ";
    for (int i = 0; i < n; i++)
    {
        cin >> prices[i];
    }

    Solution sol;
    int result = sol.maxProfit(prices);

    cout << "Maximum profit: " << result << endl;

    return 0;
}

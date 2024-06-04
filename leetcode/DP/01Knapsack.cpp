// Online C++ compiler to run C++ program online
#include <iostream>
#include <vector> // Include the vector header
using namespace std;

int knapsack(vector<int> &weight, vector<int> &value, int i, int maxWeight, vector<vector<int>> &dp)
{

    // base case(standing at 1st index,we are moving from last to first )
    if (i == 0)
    {
        if (weight[0] <= maxWeight)
        {
            return value[0];
        }
        else
        {
            return 0;
        }
    }
    if (dp[i][maxWeight] != -1)
        return dp[i][maxWeight];

    int exclude = knapsack(weight, value, i - 1, maxWeight, dp);

    int include = INT_MIN;
    if (weight[i] <= maxWeight)
    {
        include =
            value[i] + knapsack(weight, value, i - 1, maxWeight - weight[i], dp);
    }
    int profit = max(include, exclude);

    return dp[i][maxWeight] = profit;
}

int main()
{
    vector<int> value = {5, 4, 8, 6};
    vector<int> wt = {1, 2, 4, 5};
    int n = sizeof(value) / sizeof(value[0]);
    int maxWeight = 5;
    vector<vector<int>> dp(n + 1, vector<int>(maxWeight + 1, -1));
    int ans = knapsack(wt, value, n - 1, maxWeight, dp);
    cout << "max profit: " << ans;

    return 0;
}
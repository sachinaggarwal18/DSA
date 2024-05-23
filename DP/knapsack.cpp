// Online C++ compiler to run C++ program online
#include <iostream>
#include <vector> // Include the vector header
using namespace std;

int knapsack(int wt[], int cost[], int cap, int n, vector<int> &dp)
{
    // Base case: no items left or capacity is 0
    if (n == 0 || cap == 0)
        return 0;

    int profit = 0;

    if (dp[n] != -1)
        return dp[n];

    if (wt[n - 1] <= cap)
    {
        int pick = cost[n - 1] + knapsack(wt, cost, cap - wt[n - 1], n, dp);
        int notpick = knapsack(wt, cost, cap, n - 1, dp);

        profit = max(pick, notpick);
    }
    else
    {
        profit = knapsack(wt, cost, cap, n - 1, dp);
    }
    return dp[n] = profit;
}
int main()
{
    int cost[] = {5, 2, 1, 8, 7, 3};
    int wt[] = {5, 8, 9, 1, 7, 6};
    int n = sizeof(cost) / sizeof(cost[0]);
    int cap = 12;
    vector<int> dp(n + 1, -1);
    int ans = knapsack(wt, cost, cap, n, dp);
    cout << "max profit: " << ans;

    return 0;
}
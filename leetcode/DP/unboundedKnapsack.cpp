#include <vector>
#include <iostream>
using namespace std;

// Recursive approach without memoization
int solveRecursive(int ind, int maxWeight, vector<int> &profit, vector<int> &weight)
{
    if (ind == 0)
    {
        return (maxWeight / weight[0]) * profit[0];
    }

    int notTake = solveRecursive(ind - 1, maxWeight, profit, weight);
    int take = INT_MIN;
    if (weight[ind] <= maxWeight)
    {
        take = profit[ind] + solveRecursive(ind, maxWeight - weight[ind], profit, weight);
    }

    return max(take, notTake);
}

// Memoization approach
int solveMemoization(int ind, int maxWeight, vector<int> &profit, vector<int> &weight, vector<vector<int>> &dp)
{
    if (ind == 0)
    {
        return (maxWeight / weight[0]) * profit[0];
    }

    if (dp[ind][maxWeight] != -1)
    {
        return dp[ind][maxWeight];
    }

    int notTake = solveMemoization(ind - 1, maxWeight, profit, weight, dp);
    int take = INT_MIN;
    if (weight[ind] <= maxWeight)
    {
        take = profit[ind] + solveMemoization(ind, maxWeight - weight[ind], profit, weight, dp);
    }

    return dp[ind][maxWeight] = max(take, notTake);
}

int tabulation(int ind, int maxWeight, vector<int> &profit, vector<int> &weight, vector<vector<int>> &tabDp)
{
    int n = weight.size();
    for (int i = 0; i <= maxWeight; i++)
    {
        tabDp[0][i] = (i / weight[0]) * profit[0];
    }

    for (int i = 1; i < n; i++)
    {
        for (int j = 0; j <= maxWeight; j++)
        {
            int notTake = tabDp[i - 1][j];
            int take = INT_MIN;
            if (weight[i] <= j)
            {
                take = profit[i] + tabDp[i][j - weight[i]];
            }

            tabDp[i][j] = max(take, notTake);
        }
    }
    return tabDp[ind][maxWeight];
}

int spaceOptimization(int ind, int maxWeight, vector<int> &profit, vector<int> &weight)
{
    int n = weight.size();
    vector<int> prev(maxWeight + 1, 0), cur(maxWeight + 1, 0);
    for (int i = 0; i <= maxWeight; i++)
    {
        prev[i] = (i / weight[0]) * profit[0];
    }

    for (int i = 1; i < n; i++)
    {
        for (int j = 0; j <= maxWeight; j++)
        {
            int notTake = prev[j];
            int take = INT_MIN;
            if (weight[i] <= j)
            {
                take = profit[i] + cur[j - weight[i]];
            }

            cur[j] = max(take, notTake);
        }
        prev = cur;
    }
    return prev[maxWeight];
}

// Function to call the recursive approach
int unboundedKnapsackRecursive(int n, int w, vector<int> &profit, vector<int> &weight)
{
    return solveRecursive(n - 1, w, profit, weight);
}

// Function to call the memoization approach
int unboundedKnapsackMemoization(int n, int w, vector<int> &profit, vector<int> &weight)
{
    vector<vector<int>> dp(n, vector<int>(w + 1, -1));
    return solveMemoization(n - 1, w, profit, weight, dp);
}

// Function to call the tabulation approach
int unboundedKnapsackTabulation(int n, int w, vector<int> &profit, vector<int> &weight)
{
    vector<vector<int>> tabDp(n, vector<int>(w + 1, 0));
    return tabulation(n - 1, w, profit, weight, tabDp);
}

// Function to call the space optimization approach
int unboundedKnapsackSpaceOpti(int n, int w, vector<int> &profit, vector<int> &weight)
{
    return spaceOptimization(n - 1, w, profit, weight);
}

int main()
{
    int n, w;
    cout << "Enter the number of items: ";
    cin >> n;
    cout << "Enter the maximum weight capacity of the knapsack: ";
    cin >> w;

    vector<int> profit(n), weight(n);
    cout << "Enter the profit of each item: ";
    for (int i = 0; i < n; ++i)
    {
        cin >> profit[i];
    }
    cout << "Enter the weight of each item: ";
    for (int i = 0; i < n; ++i)
    {
        cin >> weight[i];
    }

    int maxProfitRecursive = unboundedKnapsackRecursive(n, w, profit, weight);
    int maxProfitMemoization = unboundedKnapsackMemoization(n, w, profit, weight);
    int maxProfitTabulation = unboundedKnapsackTabulation(n, w, profit, weight);
    int maxProfitSO = unboundedKnapsackSpaceOpti(n, w, profit, weight);

    cout << "The maximum profit using recursive approach is: " << maxProfitRecursive << endl;
    cout << "The maximum profit using memoization approach is: " << maxProfitMemoization << endl;
    cout << "The maximum profit using tabulation approach is: " << maxProfitTabulation << endl;
    cout << "The maximum profit using space optimization approach is: " << maxProfitSO << endl;

    return 0;
}

#include <iostream>
#include <vector>
using namespace std;

int recursion(int ind, vector<int> &price, int n)
{

    if (ind == 0)
    {
        return n * price[0];
    }

    int notTake = recursion(ind - 1, price, n);
    int take = INT_MIN;
    int rodLength = ind + 1;
    if (rodLength <= n)
    {
        take = price[ind] + recursion(ind, price, n - rodLength);
    }

    return max(take, notTake);
}

int memoization(int ind, vector<int> &price, int n, vector<vector<int>> &dp)
{

    if (ind == 0)
    {
        return n * price[0];
    }

    if (dp[ind][n] != -1)
    {
        return dp[ind][n];
    }

    int notTake = memoization(ind - 1, price, n, dp);
    int take = INT_MIN;
    int rodLength = ind + 1;
    if (rodLength <= n)
    {
        take = price[ind] + memoization(ind, price, n - rodLength, dp);
    }

    return dp[ind][n] = max(take, notTake);
}

int tabulation(int ind, vector<int> &price, int n, vector<vector<int>> &dp)
{

    for (int i = 0; i <= n; i++)
    {
        dp[0][i] = i * price[0];
    }

    for (int i = 1; i < n; i++)
    {
        for (int j = 0; j <= n; j++)
        {
            int notTake = dp[i - 1][j];
            int take = INT_MIN;
            int rodLength = i + 1;
            if (rodLength <= j)
            {
                take = price[i] + dp[i - 1][j - rodLength];
            }

            dp[i][j] = max(take, notTake);
        }
    }

    return dp[ind - 1][n];
}

int spaceOpti(int ind, vector<int> &price, int n)
{

    vector<int> prev(n + 1, 0), cur(n + 1, 0);

    for (int i = 0; i <= n; i++)
    {
        prev[i] = i * price[0];
    }

    for (int i = 1; i < n; i++)
    {
        for (int j = 0; j <= n; j++)
        {
            int notTake = prev[j];
            int take = INT_MIN;
            int rodLength = i + 1;
            if (rodLength <= j)
            {
                take = price[i] + cur[j - rodLength];
            }

            cur[j] = max(take, notTake);
        }
        prev = cur;
    }

    return prev[n];
}

int recusrionCall(vector<int> &price, int n)
{
    return recursion(n - 1, price, n);
}

int memoCall(vector<int> &price, int n)
{
    vector<vector<int>> dp(n, vector<int>(n + 1, -1));
    return memoization(n - 1, price, n, dp);
}

int tabCall(vector<int> &price, int n)
{
    vector<vector<int>> dp(n, vector<int>(n + 1, 0));
    return tabulation(n - 1, price, n, dp);
}

int spaceOptimizationCall(vector<int> &price, int n)
{
    vector<vector<int>> dp(n, vector<int>(n + 1, 0));
    return spaceOpti(n - 1, price, n);
}

int main()
{
    int n = 8;
    vector<int> price = {3, 5, 8, 9, 10, 17, 17, 20};

    int recAns = recusrionCall(price, n);
    cout << "Recusrion Ans: " << recAns << endl;

    int memoAns = memoCall(price, n);
    cout << "Memoization Ans: " << recAns << endl;

    int tabAns = tabCall(price, n);
    cout << "Tabulation Ans: " << tabAns << endl;

    int soAns = spaceOptimizationCall(price, n);
    cout << "Space Optimization Ans: " << soAns << endl;
}
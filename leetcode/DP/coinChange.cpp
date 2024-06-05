#include <iostream>
#include <vector>
using namespace std;

class Solution
{
public:
    int solve(int i, vector<int> &coins, int target)
    {

        if (i == 0)
        {
            if (target % coins[i] == 0)
            {
                return target / coins[i];
            }
            return -1;
        }

        int notTake = solve(i - 1, coins, target);
        int take = INT_MAX;
        if (coins[i] <= target)
        {
            take = 1 + solve(i, coins, target - coins[i]);
        }

        return min(notTake, take);
    }

    int memo(int i, vector<int> &coins, int target, vector<vector<int>> &dp)
    {
        if (i == 0)
        {
            if (target % coins[i] == 0)
            {
                return target / coins[i];
            }
            return -1;
        }

        if (dp[i][target] != -1)
        {
            return dp[i][target];
        }

        int notTake = memo(i - 1, coins, target, dp);
        int take = INT_MAX;
        if (coins[i] <= target)
        {
            take = 1 + memo(i, coins, target - coins[i], dp);
        }

        return dp[i][target] = min(take, notTake);
    }

    int tabulation(int i, vector<int> &coins, int target, vector<vector<int>> &tabDp)
    {
        int n = coins.size();
        for (int t = 0; t <= target; t++)
        {
            if (t % coins[0] == 0)
            {
                tabDp[0][t] = t / coins[0];
            }
        }

        for (int i = 1; i < n; i++)
        {
            for (int j = 0; j <= target; j++)
            {

                int notTake = tabDp[i - 1][j];
                int take = INT_MAX;
                if (coins[i] <= j)
                {
                    take = 1 + tabDp[i - 1][j - coins[i]];
                }
                tabDp[i][j] = min(take, notTake);
            }
        }

        return tabDp[n - 1][target];
    }

    int spaceOptmiziation(int i, vector<int> &coins, int target)
    {

        vector<int> prev(target + 1, 0), curr(target + 1, 0);
        int n = coins.size();
        for (int t = 0; t <= target; t++)
        {
            if (t % coins[0] == 0)
            {
                prev[t] = t / coins[0];
            }
        }

        for (int i = 1; i < n; i++)
        {
            for (int j = 0; j <= target; j++)
            {

                int notTake = prev[j];
                int take = INT_MAX;
                if (coins[i] <= j)
                {
                    take = 1 + curr[j - coins[i]];
                }
                curr[j] = min(take, notTake);
            }
            prev = curr;
        }

        return prev[target];
    }
};

int main()
{
    Solution obj;
    int n, amount;
    cout << "Enter no. of coins: " << endl;
    cin >> n;

    cout << "Enter coins: " << endl;
    vector<int> coins(n);
    for (int i = 0; i < n; i++)
    {
        cin >> coins[i];
    }

    cout << "Enter the target amount: " << endl;
    cin >> amount;

    vector<vector<int>> dp(n + 1, vector<int>(amount + 1, -1));
    vector<vector<int>> tabDp(n, vector<int>(amount + 1, INT_MAX));

    int ans1 = obj.solve(n - 1, coins, amount);
    int ans2 = obj.memo(n - 1, coins, amount, dp);
    int ans3 = obj.tabulation(n - 1, coins, amount, dp);
    int ans4 = obj.spaceOptmiziation(n - 1, coins, amount);

    if (ans4 == INT_MAX) // Corrected condition to check against INT_MAX
    {
        cout << "Ans: " << -1 << endl; // Added endl for newline
    }
    else
    {
        cout << "Ans: " << ans4 << endl; // Added endl for newline
    }
}
#include <vector>
#include <iostream>
using namespace std;

class Solution
{
public:
    // Recursive function without memoization
    long long solveRecursive(int ind, vector<int> &nums, bool flag)
    {
        if (ind >= nums.size())
        {
            return 0;
        }

        long long notTake = solveRecursive(ind + 1, nums, flag);
        long long val = nums[ind];
        if (!flag)
        {
            val = -val;
        }

        long long take = val + solveRecursive(ind + 1, nums, !flag);

        return max(notTake, take);
    }

    // Memoization function
    long long solveMemo(int ind, vector<int> &nums, bool flag, vector<vector<long long>> &dp)
    {
        if (ind >= nums.size())
        {
            return 0;
        }

        if (dp[flag][ind] != -1)
        {
            return dp[flag][ind];
        }

        long long notTake = solveMemo(ind + 1, nums, flag, dp);
        long long val = nums[ind];
        if (!flag)
        {
            val = -val;
        }

        long long take = val + solveMemo(ind + 1, nums, !flag, dp);

        return dp[flag][ind] = max(notTake, take);
    }

    // tabulation function
    long long solveTabulation(int ind, vector<int> &nums, bool flag, vector<vector<long long>> &tabDp)
    {
        int n = nums.size();

        for (int i = 0; i < n; i++)
        {
            tabDp[flag][0] = 1;
        }

        for (int i = n - 1; i >= 0; i--)
        {
            for (int j = 1; j <= 1; j++)
            {
                long long notTake = tabDp[flag][ind + 1];
                long long val = nums[ind];
                if (!flag)
                {
                    val = -val;
                }

                long long take = val + tabDp[flag][ind + 1];
                tabDp[flag][ind] = max(notTake, take);
            }
        }

        return tabDp[flag][ind];
    }

    // Function to calculate max alternating sum using memoization
    long long maxAlternatingSum(vector<int> &nums)
    {
        int n = nums.size();
        vector<vector<long long>> dp(2, vector<long long>(n, -1));
        vector<vector<long long>> tabDp(n + 1, vector<long long>(n + 1, 0));
        // return solveMemo(0, nums, true, dp);
        return solveTabulation(0, nums, true, tabDp);
    }
};

int main()
{
    Solution sol;
    int n;
    cout << "Enter the size of the array: ";
    cin >> n;
    vector<int> nums(n);
    cout << "Enter the elements of the array: ";
    for (int i = 0; i < n; ++i)
    {
        cin >> nums[i];
    }
    cout << "Maximum Alternating Sum: " << sol.maxAlternatingSum(nums) << endl;
    return 0;
}

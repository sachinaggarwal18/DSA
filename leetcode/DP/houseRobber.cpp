#include <iostream>
#include <vector>
using namespace std;

class Solution
{
public:
    int solve(vector<int> &nums, int n)
    {
        // base case
        if (n >= nums.size())
        {
            return 0;
        }

        if (n == nums.size() - 1)
        {
            return nums[n];
        }

        int include = solve(nums, n + 2) + nums[n];
        int exclude = solve(nums, n + 1) + 0;

        return max(include, exclude);
    }

    int rob(vector<int> &nums)
    {
        return solve(nums, 0);
    }
};

int main()
{
    Solution sol;

    int n;
    cout << "Enter the number of houses: ";
    cin >> n;

    vector<int> nums(n);
    cout << "Enter the amount of money in each house: ";
    for (int i = 0; i < n; ++i)
    {
        cin >> nums[i];
    }

    int maxMoney = sol.rob(nums);
    cout << "The maximum amount of money that can be robbed is: " << maxMoney << endl;

    return 0;
}

#include <iostream>
#include <vector>
#include <cstring> // for memset

using namespace std;

class Solution
{
public:
    int t[201][1001];
    int n;

    int solve(int ind, vector<int> &nums, int target)
    {
        if (target == 0)
        {
            return 1;
        }

        if (ind >= n || target < 0)
        {
            return 0;
        }

        if (t[ind][target] != -1)
        {
            return t[ind][target];
        }

        int result = 0;

        for (int i = ind; i < n; i++)
        {
            int take = solve(0, nums, target - nums[i]);
            result += take;
        }

        return t[ind][target] = result;
    }

    int combinationSum4(vector<int> &nums, int target)
    {
        n = nums.size();
        memset(t, -1, sizeof(t));
        return solve(0, nums, target);
    }
};

int main()
{
    Solution solution;
    int n, target;

    cout << "Enter the number of elements in the array: ";
    cin >> n;

    vector<int> nums(n);
    cout << "Enter the elements of the array: ";
    for (int i = 0; i < n; i++)
    {
        cin >> nums[i];
    }

    cout << "Enter the target sum: ";
    cin >> target;

    int result = solution.combinationSum4(nums, target);

    cout << "Number of combinations that sum up to " << target << ": " << result << endl;

    return 0;
}

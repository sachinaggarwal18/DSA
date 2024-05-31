#include <iostream>
#include <vector>
#include <unordered_map>

using namespace std;

class Solution
{
public:
    int count = 0;

    void solve(int ind, vector<int> &nums, unordered_map<int, int> &mp, int k)
    {
        if (ind >= nums.size())
        {
            count++;
            return;
        }

        // take
        if (!mp[nums[ind] - k] && !mp[nums[ind] + k])
        {
            mp[nums[ind]]++;
            solve(ind + 1, nums, mp, k);
            mp[nums[ind]]--;
        }

        // notTake
        solve(ind + 1, nums, mp, k);
    }

    int beautifulSubsets(vector<int> &nums, int k)
    {
        unordered_map<int, int> mp;
        solve(0, nums, mp, k);
        return count - 1; // Exclude the empty subset
    }
};

int main()
{
    Solution solution;

    vector<int> nums1 = {2, 4, 6};
    int k1 = 2;
    cout << "Number of beautiful subsets for nums1: " << solution.beautifulSubsets(nums1, k1) << endl;

    vector<int> nums2 = {1};
    int k2 = 1;
    cout << "Number of beautiful subsets for nums2: " << solution.beautifulSubsets(nums2, k2) << endl;

    return 0;
}

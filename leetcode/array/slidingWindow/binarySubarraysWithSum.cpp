#include <iostream>
#include <vector>
#include <unordered_map>

using namespace std;

class Solution
{
public:
    int numSubarraysWithSum(vector<int> &nums, int goal)
    {
        unordered_map<int, int> mp;
        int sum = 0, ans = 0;

        mp[0] = 1; // Initialize the map with sum 0 to handle cases where subarray starts from index 0

        for (int i = 0; i < nums.size(); i++)
        {
            sum += nums[i];

            if (mp.find(sum - goal) != mp.end())
            {
                ans += mp[sum - goal];
            }
            mp[sum]++;
        }

        return ans;
    }
};

int main()
{
    Solution solution;
    vector<int> nums1 = {1, 0, 1, 0, 1};
    int goal1 = 2;
    cout << "Number of subarrays with sum " << goal1 << " in nums1: " << solution.numSubarraysWithSum(nums1, goal1) << endl;

    vector<int> nums2 = {0, 0, 0, 0, 0};
    int goal2 = 0;
    cout << "Number of subarrays with sum " << goal2 << " in nums2: " << solution.numSubarraysWithSum(nums2, goal2) << endl;

    return 0;
}
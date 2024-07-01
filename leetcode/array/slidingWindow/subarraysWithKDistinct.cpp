#include <iostream>
#include <vector>
#include <unordered_map>

using namespace std;

class Solution
{
public:
    int solve(vector<int> &nums, int k)
    {
        unordered_map<int, int> mp;
        int cnt = 0, n = nums.size(), l = 0, r = 0;

        while (r < n)
        {
            mp[nums[r]]++;

            while (mp.size() > k)
            {
                mp[nums[l]]--;
                if (mp[nums[l]] == 0)
                {
                    mp.erase(nums[l]);
                }
                l++;
            }

            cnt += r - l + 1; //<=k waale bhi count h isme
            r++;
        }
        return cnt;
    }

    int subarraysWithKDistinct(vector<int> &nums, int k)
    {
        return solve(nums, k) - solve(nums, k - 1); //<=k hatane k lie
    }
};

int main()
{
    Solution sol;

    vector<int> nums1 = {1, 2, 1, 2, 3};
    int k1 = 2;
    cout << "Result for nums1: " << sol.subarraysWithKDistinct(nums1, k1) << endl; // Expected output: 7

    vector<int> nums2 = {1, 2, 1, 3, 4};
    int k2 = 3;
    cout << "Result for nums2: " << sol.subarraysWithKDistinct(nums2, k2) << endl; // Expected output: 3

    return 0;
}
#include <iostream>
#include <vector>
#include <unordered_map>

using namespace std;

class Solution
{
public:
    int numberOfSubarrays(vector<int> &nums, int k)
    {
        int n = nums.size();
        int oddCount = 0, ans = 0;
        unordered_map<int, int> mp;
        mp[oddCount] = 1;

        for (int i = 0; i < n; i++)
        {
            if (nums[i] % 2 != 0)
            {
                oddCount++;
            }

            if (mp.find(oddCount - k) != mp.end())
            {
                ans += mp[oddCount - k];
            }

            mp[oddCount]++;
        }

        return ans;
    }
};

int main()
{
    Solution solution;

    // Test case 1
    vector<int> nums1 = {2, 1, 2, 1};
    int k1 = 1;
    cout << "Number of subarrays with exactly " << k1 << " odd numbers: " << solution.numberOfSubarrays(nums1, k1) << endl;

    // Test case 2
    vector<int> nums2 = {2, 4, 6};
    int k2 = 1;
    cout << "Number of subarrays with exactly " << k2 << " odd numbers: " << solution.numberOfSubarrays(nums2, k2) << endl;

    // Test case 3
    vector<int> nums3 = {2, 2, 2, 1, 2, 2, 1, 2, 2, 2};
    int k3 = 2;
    cout << "Number of subarrays with exactly " << k3 << " odd numbers: " << solution.numberOfSubarrays(nums3, k3) << endl;

    return 0;
}

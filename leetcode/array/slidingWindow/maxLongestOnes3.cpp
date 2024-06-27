#include <iostream>
#include <vector>
#include <algorithm>

class Solution
{
public:
    int longestOnes(std::vector<int> &nums, int k)
    {
        int n = nums.size(), l = 0, r = 0, zeroCnt = 0, ans = 0;

        while (r < n)
        {
            if (nums[r] == 0)
                zeroCnt++;

            if (zeroCnt > k)
            {
                if (nums[l] == 0)
                    zeroCnt--;
                l++;
            }

            ans = std::max(ans, r - l + 1);
            r++;
        }
        return ans;
    }
};

int main()
{
    Solution sol;

    // Test Case 1
    std::vector<int> nums1 = {1, 1, 1, 0, 0, 0, 1, 1, 1, 1, 0};
    int k1 = 2;
    std::cout << "Longest sequence of ones after at most " << k1 << " flips: " << sol.longestOnes(nums1, k1) << std::endl;

    // Test Case 2
    std::vector<int> nums2 = {0, 0, 1, 1, 0, 0, 1, 1, 1, 0, 1, 1, 0, 0, 0, 1, 1, 1, 1};
    int k2 = 3;
    std::cout << "Longest sequence of ones after at most " << k2 << " flips: " << sol.longestOnes(nums2, k2) << std::endl;

    // Test Case 3
    std::vector<int> nums3 = {0, 0, 0, 0};
    int k3 = 0;
    std::cout << "Longest sequence of ones after at most " << k3 << " flips: " << sol.longestOnes(nums3, k3) << std::endl;

    return 0;
}
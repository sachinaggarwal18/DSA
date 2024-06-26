#include <iostream>
#include <vector>
using namespace std;

class Solution
{
public:
    int numSubarrayProductLessThanK(vector<int> &nums, int k)
    {
        if (k <= 1)
            return 0;

        int l = 0, r = 0, cnt = 0;
        int n = nums.size();
        int prod = 1;

        while (r < n)
        {
            prod *= nums[r];

            while (prod >= k)
            {
                prod /= nums[l];
                l++;
            }
            cnt += (r - l + 1);
            r++;
        }

        return cnt;
    }
};

int main()
{
    Solution sol;
    vector<int> nums1 = {10, 5, 2, 6};
    int k1 = 100;
    cout << "Test Case 1: " << sol.numSubarrayProductLessThanK(nums1, k1) << endl;

    vector<int> nums2 = {1, 2, 3};
    int k2 = 0;
    cout << "Test Case 2: " << sol.numSubarrayProductLessThanK(nums2, k2) << endl;

    vector<int> nums3 = {10, 2, 2, 5, 4};
    int k3 = 50;
    cout << "Test Case 3: " << sol.numSubarrayProductLessThanK(nums3, k3) << endl;

    return 0;
}
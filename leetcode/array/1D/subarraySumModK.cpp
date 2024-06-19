#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;

class Solution
{
public:
    bool checkSubarraySum(vector<int> &nums, int k)
    {
        int n = nums.size(), sum = 0;
        unordered_map<int, int> mpp;
        mpp[0] = -1; // To handle cases where the subarray starts from the beginning

        for (int i = 0; i < n; i++)
        {
            sum += nums[i];
            int remainder = sum % k;

            if (remainder < 0)
            {
                remainder += k; // Adjust for negative remainders
            }

            // Check if remainder is already in the map
            if (mpp.find(remainder) != mpp.end())
            {
                // Ensure subarray length is at least two
                if (i - mpp[remainder] >= 2)
                {
                    return true;
                }
            }
            else
            {
                // If remainder is not found, add it to the map
                mpp[remainder] = i;
            }
        }
        return false;
    }
};

int main()
{
    Solution sol;
    int n, k;

    cout << "Enter the number of elements in the array: ";
    cin >> n;

    vector<int> nums(n);
    cout << "Enter the elements of the array: ";
    for (int i = 0; i < n; ++i)
    {
        cin >> nums[i];
    }

    cout << "Enter the value of k: ";
    cin >> k;

    bool result = sol.checkSubarraySum(nums, k);
    cout << (result ? "true" : "false") << endl;

    return 0;
}

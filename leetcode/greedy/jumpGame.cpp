#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class Solution
{
public:
    bool canJump(vector<int> &nums)
    {
        int max_ind = 0;
        int n = nums.size();

        for (int i = 0; i < n; i++)
        {
            if (i > max_ind)
                return false;
            max_ind = max(max_ind, i + nums[i]);
        }

        return max_ind >= n - 1;
    }
};

int main()
{
    int n;
    cout << "Enter the number of elements in the array: ";
    cin >> n;

    vector<int> nums(n);
    cout << "Enter the elements of the array: ";
    for (int i = 0; i < n; i++)
    {
        cin >> nums[i];
    }

    Solution solution;
    bool result = solution.canJump(nums);

    cout << "Output: " << (result ? "true" : "false") << endl;

    return 0;
}

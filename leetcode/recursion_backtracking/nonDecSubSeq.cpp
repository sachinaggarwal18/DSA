#include <vector>
#include <unordered_set>
#include <iostream>

using namespace std;

class Solution
{
public:
    vector<vector<int>> res;
    vector<int> ans;

    void solve(vector<int> &nums, int ind, int n)
    {
        if (ans.size() >= 2)
        {
            res.push_back(ans);
        }
        unordered_set<int> st;

        for (int i = ind; i < n; i++)
        {
            if ((ans.empty() || nums[i] >= ans.back()) &&
                st.find(nums[i]) == st.end())
            {
                ans.push_back(nums[i]);
                solve(nums, i + 1, n);
                ans.pop_back();

                st.insert(nums[i]);
            }
        }
    }

    vector<vector<int>> findSubsequences(vector<int> &nums)
    {
        solve(nums, 0, nums.size());
        return res;
    }
};

int main()
{
    Solution solution;
    vector<int> nums1 = {4, 6, 7, 7};
    vector<int> nums2 = {4, 2, 3, 6, 7, 3, 1};

    vector<vector<int>> result1 = solution.findSubsequences(nums1);
    vector<vector<int>> result2 = solution.findSubsequences(nums2);

    cout << "Unique non-decreasing subsequences for nums1:" << endl;
    for (const auto &seq : result1)
    {
        for (int num : seq)
        {
            cout << num << " ";
        }
        cout << endl;
    }

    cout << "Unique non-decreasing subsequences for nums2:" << endl;
    for (const auto &seq : result2)
    {
        for (int num : seq)
        {
            cout << num << " ";
        }
        cout << endl;
    }

    return 0;
}

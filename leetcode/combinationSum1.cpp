#include <iostream>
#include <vector>

using namespace std;

class Solution
{
public:
    vector<vector<int>> ans;

    void solve(int ind, int target, vector<int> temp, vector<int> &candidates)
    {
        if (ind == candidates.size())
        {
            if (target == 0)
            {
                ans.push_back(temp);
            }
            return;
        }

        // pick
        if (candidates[ind] <= target)
        {
            temp.push_back(candidates[ind]);
            solve(ind, target - candidates[ind], temp, candidates);
            temp.pop_back(); // backtrack
        }

        // not pick
        solve(ind + 1, target, temp, candidates);
    }

    vector<vector<int>> combinationSum(vector<int> &candidates, int target)
    {
        vector<int> temp;
        solve(0, target, temp, candidates);
        return ans;
    }
};

int main()
{
    Solution solution;
    int n, target;

    cout << "Enter the number of candidates: ";
    cin >> n;

    vector<int> candidates(n);
    cout << "Enter the candidates: ";
    for (int i = 0; i < n; i++)
    {
        cin >> candidates[i];
    }

    cout << "Enter the target: ";
    cin >> target;

    vector<vector<int>> result = solution.combinationSum(candidates, target);

    // Print the results
    cout << "Combinations that sum up to " << target << ":\n";
    for (const auto &combination : result)
    {
        cout << "[ ";
        for (int num : combination)
        {
            cout << num << " ";
        }
        cout << "]\n";
    }

    return 0;
}

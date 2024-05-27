#include <iostream>
#include <vector>

using namespace std;

class Solution
{
public:
    vector<vector<int>> res;
    vector<int> temp;

    void solve(int ind, int n, int k)
    {
        if (k == 0)
        {
            res.push_back(temp);
            return;
        }

        for (int i = ind; i <= n; i++)
        {
            temp.push_back(i);
            solve(i + 1, n, k - 1);
            temp.pop_back();
        }
    }

    vector<vector<int>> combine(int n, int k)
    {
        solve(1, n, k);
        return res;
    }
};

int main()
{
    Solution solution;
    int n, k;

    cout << "Enter the value of n: ";
    cin >> n;
    cout << "Enter the value of k: ";
    cin >> k;

    if (n < k)
    {
        cout << "Error!! Enter 'k' value less than 'n'" << endl;
        return 1;
    }

    vector<vector<int>> combinations = solution.combine(n, k);

    // Print the results
    cout << "Combinations of " << k << " numbers out of 1 to " << n << ":\n";
    for (const auto &combination : combinations)
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

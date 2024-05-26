#include <vector>
#include <algorithm>
#include <climits>
#include <iostream>

using namespace std;

class Solution
{
public:
    int res = INT_MAX, n;

    void solve(vector<int> &cookies, int k, int ind, vector<int> &children)
    {
        n = cookies.size();

        if (ind >= n)
        {
            int unfairness = *max_element(begin(children), end(children));
            res = min(res, unfairness);
            return;
        }

        for (int i = 0; i < k; i++)
        {
            children[i] += cookies[ind];
            solve(cookies, k, ind + 1, children);
            children[i] -= cookies[ind];
        }
    }

    int distributeCookies(vector<int> &cookies, int k)
    {
        vector<int> children(k, 0);
        solve(cookies, k, 0, children);
        return res;
    }
};

int main()
{
    Solution solution;

    vector<int> cookies1 = {8, 15, 10, 20, 8};
    int k1 = 2;
    int result1 = solution.distributeCookies(cookies1, k1);
    cout << "Minimum unfairness for cookies1: " << result1 << endl; // Expected output: 31

    vector<int> cookies2 = {6, 1, 3, 2, 2, 4, 1, 2};
    int k2 = 3;
    int result2 = solution.distributeCookies(cookies2, k2);
    cout << "Minimum unfairness for cookies2: " << result2 << endl; // Expected output: 7

    return 0;
}

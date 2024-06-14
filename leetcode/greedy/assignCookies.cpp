#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class Solution
{
public:
    int findContentChildren(vector<int> &g, vector<int> &s)
    {
        sort(g.begin(), g.end());
        sort(s.begin(), s.end());

        int ans = 0, i = 0, j = 0;
        int n = g.size(), m = s.size();

        while (i < n && j < m)
        {
            if (s[j] >= g[i])
            {
                ans++;
                i++;
                j++;
            }
            else
            {
                j++;
            }
        }

        return ans;
    }
};

int main()
{
    Solution sol;
    int n, m;
    cout << "Enter the number of children: ";
    cin >> n;
    cout << "Enter the number of cookies: ";
    cin >> m;

    vector<int> g(n), s(m);
    cout << "Enter the greed factors of the children: ";
    for (int i = 0; i < n; i++)
    {
        cin >> g[i];
    }
    cout << "Enter the sizes of the cookies: ";
    for (int j = 0; j < m; j++)
    {
        cin >> s[j];
    }

    int result = sol.findContentChildren(g, s);
    cout << "Maximum number of content children: " << result << endl;

    return 0;
}

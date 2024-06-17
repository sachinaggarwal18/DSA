#include <iostream>
#include <vector>
#include <algorithm>
#include <map>

using namespace std;
class Solution
{
public:
    vector<int> findDiagonalOrder(vector<vector<int>> &mat)
    {
        int m = mat.size();
        int n = mat[0].size();
        map<int, vector<int>> mp;
        vector<int> ans;

        for (int i = 0; i < m; i++)
        {
            for (int j = 0; j < n; j++)
            {
                mp[i + j].push_back(mat[i][j]);
            }
        }

        bool flag = true;
        for (auto &it : mp)
        {
            if (flag)
            {
                reverse(it.second.begin(), it.second.end());
            }

            for (auto &num : it.second)
            {
                ans.push_back(num);
            }
            flag = !flag;
        }

        return ans;
    }
};

int main()
{
    Solution sol;
    vector<vector<int>> mat = {
        {11, 25, 66, 1, 69, 7}, {23, 55, 17, 45, 15, 52}, {75, 31, 36, 44, 58, 8}, {22, 27, 33, 25, 68, 4}, {84, 28, 14, 11, 5, 50}};

    vector<int> result = sol.findDiagonalOrder(mat);

    for (const auto &num : result)
    {
        std::cout << num << " ";
    }
    std::cout << std::endl;

    return 0;
}
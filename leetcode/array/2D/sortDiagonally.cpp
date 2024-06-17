#include <iostream>
#include <vector>
#include <algorithm>
#include <unordered_map>

using namespace std;
class Solution
{
public:
    vector<vector<int>> diagonalSort(vector<vector<int>> &mat)
    {
        int m = mat.size();
        int n = mat[0].size();
        unordered_map<int, vector<int>> mp;

        for (int i = 0; i < m; i++)
        {
            for (int j = 0; j < n; j++)
            {
                mp[i - j].push_back(mat[i][j]);
            }
        }

        for (auto &it : mp)
        {
            sort(it.second.begin(), it.second.end());
        }

        for (int i = m - 1; i >= 0; i--)
        {
            for (int j = n - 1; j >= 0; j--)
            {
                mat[i][j] = mp[i - j].back();
                mp[i - j].pop_back();
            }
        }

        return mat;
    }
};

int main()
{
    Solution sol;
    vector<vector<int>> mat = {
        {11, 25, 66, 1, 69, 7}, {23, 55, 17, 45, 15, 52}, {75, 31, 36, 44, 58, 8}, {22, 27, 33, 25, 68, 4}, {84, 28, 14, 11, 5, 50}};

    vector<vector<int>> result = sol.diagonalSort(mat);

    // Print the sorted matrix
    for (const auto &row : result)
    {
        for (const auto &element : row)
        {
            cout << element << " ";
        }
        cout << endl;
    }

    return 0;
}
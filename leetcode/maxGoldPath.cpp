#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class Solution
{
public:
    int solve(vector<vector<int>> &grid, int i, int j)
    {
        int m = grid.size();
        int n = grid[0].size();

        if (i >= m || i < 0 || j >= n || j < 0 || grid[i][j] == 0)
        {
            return 0;
        }

        int val = grid[i][j];
        grid[i][j] = 0;
        int maxGold = 0;

        int up = solve(grid, i + 1, j);
        int down = solve(grid, i - 1, j);
        int left = solve(grid, i, j + 1);
        int right = solve(grid, i, j - 1);

        maxGold = max({up, down, left, right});

        grid[i][j] = val;
        return val + maxGold;
    }

    int getMaximumGold(vector<vector<int>> &grid)
    {
        int m = grid.size();
        int n = grid[0].size();

        int maxGold = 0;
        for (int i = 0; i < m; i++)
        {
            for (int j = 0; j < n; j++)
            {
                if (grid[i][j] != 0)
                { // it has gold
                    maxGold = max(maxGold, solve(grid, i, j));
                }
            }
        }

        return maxGold;
    }
};

int main()
{
    Solution solution;

    // Example 1
    vector<vector<int>> grid1 = {
        {0, 6, 0},
        {5, 8, 7},
        {0, 9, 0}};
    cout << "Maximum Gold for grid1: " << solution.getMaximumGold(grid1) << endl;

    // Example 2
    vector<vector<int>> grid2 = {
        {1, 0, 7},
        {2, 0, 6},
        {3, 4, 5},
        {0, 3, 0},
        {9, 0, 20}};
    cout << "Maximum Gold for grid2: " << solution.getMaximumGold(grid2) << endl;

    // Example 3
    vector<vector<int>> grid3 = {
        {0, 0, 0},
        {0, 0, 0},
        {0, 0, 0}};
    cout << "Maximum Gold for grid3: " << solution.getMaximumGold(grid3) << endl;

    return 0;
}

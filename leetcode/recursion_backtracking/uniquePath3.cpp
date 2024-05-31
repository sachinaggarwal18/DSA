#include <vector>
#include <iostream>

using namespace std;

class Solution
{
public:
    int m, n;
    int nonObstacles = 0, ans = 0;

    void solve(vector<vector<int>> &grid, int count, int i, int j)
    {
        if (i < 0 || j < 0 || i >= m || j >= n || grid[i][j] == -1)
        {
            return;
        }

        if (grid[i][j] == 2)
        {
            if (count == nonObstacles)
            {
                ans++;
            }
            return;
        }

        // Mark the cell as visited
        int temp = grid[i][j];
        grid[i][j] = -1; // mark as visited

        solve(grid, count + 1, i + 1, j);
        solve(grid, count + 1, i, j + 1);
        solve(grid, count + 1, i, j - 1);
        solve(grid, count + 1, i - 1, j);

        grid[i][j] = temp;
    }

    int uniquePathsIII(vector<vector<int>> &grid)
    {

        m = grid.size();
        n = grid[0].size();
        int start_x = 0, start_y = 0;

        for (int i = 0; i < m; i++)
        {
            for (int j = 0; j < n; j++)
            {

                if (grid[i][j] == 0 || grid[i][j] == 1)
                {
                    nonObstacles++;
                }

                if (grid[i][j] == 1)
                {
                    start_x = i;
                    start_y = j;
                }
            }
        }

        solve(grid, 0, start_x, start_y);
        return ans;
    }
};

int main()
{
    Solution solution;
    vector<vector<int>> grid1 = {
        {1, 0, 0, 0},
        {0, 0, 0, 0},
        {0, 0, 2, -1}};

    vector<vector<int>> grid2 = {
        {1, 0, 0, 0},
        {0, 0, 0, 0},
        {0, 0, 0, 2}};

    vector<vector<int>> grid3 = {
        {0, 1},
        {2, 0}};

    cout << "Unique Paths for grid1: " << solution.uniquePathsIII(grid1) << endl; // Output: 2
    cout << "Unique Paths for grid2: " << solution.uniquePathsIII(grid2) << endl; // Output: 4
    cout << "Unique Paths for grid3: " << solution.uniquePathsIII(grid3) << endl; // Output: 0

    return 0;
}

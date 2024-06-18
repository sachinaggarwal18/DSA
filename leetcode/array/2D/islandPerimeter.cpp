#include <iostream>
#include <vector>
using namespace std;

class Solution
{
public:
    int m, n, peri = 0;
    void dfs(vector<vector<int>> &grid, int i, int j)
    {
        // Boundary condition and water check for perimeter
        if (i < 0 || i >= m || j < 0 || j >= n || grid[i][j] == 0)
        {
            peri++;
            return;
        }

        if (grid[i][j] == -1)
        {
            return;
        }

        grid[i][j] = -1; // mark visited

        dfs(grid, i + 1, j);
        dfs(grid, i, j + 1);
        dfs(grid, i, j - 1);
        dfs(grid, i - 1, j);
    }

    int islandPerimeter(vector<vector<int>> &grid)
    {
        m = grid.size();
        n = grid[0].size();

        for (int r = 0; r < m; r++)
        {
            for (int c = 0; c < n; c++)
            {
                if (grid[r][c] == 1)
                {
                    dfs(grid, r, c);
                    return peri;
                }
            }
        }
        return -1;
    }
};

int main()
{
    Solution solution;
    int m, n;

    cout << "Enter the number of rows: ";
    cin >> m;
    cout << "Enter the number of columns: ";
    cin >> n;

    vector<vector<int>> grid(m, vector<int>(n));
    cout << "Enter the grid elements (0 for water, 1 for land): " << endl;
    for (int i = 0; i < m; i++)
    {
        for (int j = 0; j < n; j++)
        {
            cin >> grid[i][j];
        }
    }

    int result = solution.islandPerimeter(grid);
    cout << "The perimeter of the island is: " << result << endl;

    return 0;
}

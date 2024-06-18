#include <iostream>
#include <vector>
using namespace std;

class Solution
{
public:
    int m, n, peri = 0;
    void dfs(vector<vector<char>> &grid, int i, int j)
    {
        // Boundary condition and water check for perimeter
        if (i < 0 || i >= m || j < 0 || j >= n || grid[i][j] == '0')
        {
            peri++;
            return;
        }

        if (grid[i][j] == '$')
        {
            return;
        }

        grid[i][j] = '$'; // mark visited

        dfs(grid, i + 1, j);
        dfs(grid, i, j + 1);
        dfs(grid, i, j - 1);
        dfs(grid, i - 1, j);
    }

    int numIslands(vector<vector<char>> &grid)
    {
        m = grid.size();
        n = grid[0].size();
        int count = 0;

        for (int r = 0; r < m; r++)
        {
            for (int c = 0; c < n; c++)
            {
                if (grid[r][c] == '1')
                {
                    count++;
                    dfs(grid, r, c);
                }
            }
        }
        return count;
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

    vector<vector<char>> grid(m, vector<char>(n));
    cout << "Enter the grid elements (0 for water, 1 for land): " << endl;
    for (int i = 0; i < m; i++)
    {
        for (int j = 0; j < n; j++)
        {
            cin >> grid[i][j];
        }
    }

    int result = solution.numIslands(grid);
    cout << "Number of islands: " << result << endl;

    return 0;
}

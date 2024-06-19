#include <iostream>
#include <vector>
#include <map>
using namespace std;

class Solution
{
public:
    // Brute force approach
    int equalPairsBruteForce(vector<vector<int>> &grid)
    {
        int n = grid.size();
        int ans = 0;

        for (int r = 0; r < n; r++)
        {
            for (int c = 0; c < n; c++)
            {
                bool flag = true;
                for (int i = 0; i < n; i++)
                {
                    if (grid[r][i] != grid[i][c])
                    {
                        flag = false;
                        break;
                    }
                }
                if (flag)
                {
                    ans++;
                }
            }
        }

        return ans;
    }

    // Optimized approach using map
    int equalPairsOptimized(vector<vector<int>> &grid)
    {
        int n = grid.size();
        int ans = 0;
        map<vector<int>, int> mp;

        // Store all rows in a map
        for (int r = 0; r < n; r++)
        {
            mp[grid[r]]++;
        }

        // Now iterate in every column
        for (int c = 0; c < n; c++)
        {
            vector<int> temp;
            for (int r = 0; r < n; r++)
            {
                temp.push_back(grid[r][c]);
            }
            ans += mp[temp];
        }

        return ans;
    }

    // Combined method that decides based on input size
    int equalPairs(vector<vector<int>> &grid)
    {
        int n = grid.size();
        if (n <= 100)
        {
            return equalPairsBruteForce(grid);
        }
        else
        {
            return equalPairsOptimized(grid);
        }
    }
};

int main()
{
    int n;
    cout << "Enter the size of the grid: ";
    cin >> n;

    vector<vector<int>> grid(n, vector<int>(n));
    cout << "Enter the elements of the grid row by row:" << endl;

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            cin >> grid[i][j];
        }
    }

    Solution sol;
    int result = sol.equalPairs(grid);

    cout << "Number of equal pairs: " << result << endl;

    return 0;
}

// Online C++ compiler to run C++ program online
#include <iostream>
using namespace std;

int uniquePaths(int i, int j, int m, int n, vector<vector<int>> &dp)
{

    if (i == m - 1 && j == n - 1)
        return 1;

    if (i >= m || j >= n)
        return 0;

    if (dp[i][j] != -1)
        return dp[i][j];

    int right = uniquePaths(i, j + 1, m, n, dp);
    int down = uniquePaths(i + 1, j, m, n, dp);
    int diagonal = uniquePaths(i + 1, j + 1, m, n, dp);

    return dp[i][j] = right + down + diagonal;
}
int main()
{
    int m = 10, n = 10;
    // vector<vector<int>> dp(m, vector<int>(n, -1));
    vector<vector<int>> dp(m, vector<int>(n, -1)); // Add space between consecutive right angle brackets

    int ans = uniquePaths(0, 0, m, n, dp);
    cout << "Number of unique paths: " << ans;

    return 0;
}
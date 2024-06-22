#include <iostream>
#include <vector>

using namespace std;

class Solution
{
public:
    vector<vector<int>> diagonal(vector<vector<int>> &A)
    {
        int n = A.size();
        vector<vector<int>> result(2 * n - 1); // Initialize result with appropriate size

        for (int i = 0; i < n; ++i)
        {
            for (int j = 0; j < n; ++j)
            {
                result[i + j].push_back(A[i][j]);
            }
        }

        return result;
    }
};

int main()
{
    Solution solution;

    // Test Case 1
    vector<vector<int>> matrix1 = {
        {1, 2, 3},
        {4, 5, 6},
        {7, 8, 9}};
    vector<vector<int>> result1 = solution.diagonal(matrix1);
    cout << "Test Case 1:" << endl;
    for (const auto &diag : result1)
    {
        for (int num : diag)
        {
            cout << num << " ";
        }
        cout << endl;
    }

    // Test Case 2
    vector<vector<int>> matrix2 = {
        {1, 2},
        {3, 4}};
    vector<vector<int>> result2 = solution.diagonal(matrix2);
    cout << "\nTest Case 2:" << endl;
    for (const auto &diag : result2)
    {
        for (int num : diag)
        {
            cout << num << " ";
        }
        cout << endl;
    }

    return 0;
}

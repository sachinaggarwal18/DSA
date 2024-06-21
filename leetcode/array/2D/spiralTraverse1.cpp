#include <iostream>
#include <vector>

using namespace std;

class Solution
{
public:
    vector<int> spiralOrder(vector<vector<int>> &matrix)
    {
        int m = matrix.size();
        int n = matrix[0].size();

        int left = 0;
        int top = 0;
        int right = n - 1;
        int bottom = m - 1;
        int dir = 0;

        vector<int> ans;

        while (top <= bottom && left <= right)
        {
            if (dir == 0)
            {
                // left to right
                for (int i = left; i <= right; i++)
                {
                    ans.push_back(matrix[top][i]);
                }
                top++;
            }
            else if (dir == 1)
            { // top to bottom
                for (int i = top; i <= bottom; i++)
                {
                    ans.push_back(matrix[i][right]);
                }
                right--;
            }
            else if (dir == 2)
            {
                // right to left
                for (int i = right; i >= left; i--)
                {
                    ans.push_back(matrix[bottom][i]);
                }
                bottom--;
            }
            else if (dir == 3)
            {
                // bottom to top
                for (int i = bottom; i >= top; i--)
                {
                    ans.push_back(matrix[i][left]);
                }
                left++;
            }
            dir++;
            if (dir == 4)
                dir = 0;
        }

        return ans;
    }
};

int main()
{
    Solution solution;

    // Example matrix
    vector<vector<int>> matrix = {
        {1, 2, 3},
        {4, 5, 6},
        {7, 8, 9}};

    // Get the spiral order
    vector<int> result = solution.spiralOrder(matrix);

    // Print the result
    cout << "Spiral order: ";
    for (int num : result)
    {
        cout << num << " ";
    }
    cout << endl;

    return 0;
}

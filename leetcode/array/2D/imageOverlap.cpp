#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class Solution
{
public:
    int countOverlaps(vector<vector<int>> &A, vector<vector<int>> &B,
                      int row_offset, int col_offset)
    {

        int count = 0;
        int n = A.size();

        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < n; j++)
            {

                int B_i = i + row_offset;
                int B_j = j + col_offset;

                if (B_i < 0 || B_i >= n || B_j < 0 || B_j >= n)
                    continue;

                if (A[i][j] == 1 && B[B_i][B_j] == 1)
                {
                    count++;
                }
            }
        }

        return count;
    }

    int largestOverlap(vector<vector<int>> &img1, vector<vector<int>> &img2)
    {

        int n = img1.size();
        int maxoverlap = 0;
        for (int row_offset = -n + 1; row_offset < n; row_offset++)
        {
            for (int col_offset = -n + 1; col_offset < n; col_offset++)
            {
                int count = countOverlaps(img1, img2, row_offset, col_offset);

                maxoverlap = max(maxoverlap, count);
            }
        }

        return maxoverlap;
    }
};

int main()
{
    Solution solution;

    vector<vector<int>> img1 = {
        {1, 1, 0},
        {0, 1, 0},
        {0, 1, 0}};

    vector<vector<int>> img2 = {
        {0, 0, 0},
        {0, 1, 1},
        {0, 0, 1}};

    int result = solution.largestOverlap(img1, img2);
    cout << "Largest Overlap: " << result << endl;

    return 0;
}

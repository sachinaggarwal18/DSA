#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class Solution
{
public:
    static bool comparator(const vector<int> &m1, const vector<int> &m2)
    {
        // Use const references for efficiency and avoid unnecessary copying
        return m1[1] < m2[1];
    }

    int eraseOverlapIntervals(vector<vector<int>> &intervals)
    {
        int n = intervals.size();

        sort(intervals.begin(), intervals.end(), comparator);

        int lastMeet = intervals[0][1], count = 1;

        for (int i = 1; i < n; i++)
        {
            if (intervals[i][0] >= lastMeet)
            {
                count++;
                lastMeet = intervals[i][1];
            }
        }

        return n - count;
    }
};
int main()
{
    // vector<vector<int>> intervals = {{1, 2}, {2, 3}, {3, 4}, {1, 3}};
    vector<vector<int>> intervals = {{1, 2}, {1, 2}, {1, 2}};

    Solution solution;
    int removedIntervals = solution.eraseOverlapIntervals(intervals);

    cout << "Number of intervals to be removed: " << removedIntervals << endl;

    return 0;
}

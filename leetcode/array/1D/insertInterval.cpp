#include <iostream>
#include <vector>

using namespace std;

class Solution
{
public:
    vector<vector<int>> insert(vector<vector<int>> &intervals,
                               vector<int> &newInterval)
    {

        vector<vector<int>> ans;
        int i = 0, n = intervals.size();

        // Left non-overlapping intervals
        while (i < n && intervals[i][1] < newInterval[0])
        {
            ans.push_back(intervals[i]);
            i++;
        }

        // Merge overlapping intervals
        while (i < n && intervals[i][0] <= newInterval[1])
        {
            newInterval[0] = min(newInterval[0], intervals[i][0]);
            newInterval[1] = max(newInterval[1], intervals[i][1]);
            i++;
        }
        ans.push_back(newInterval);

        // Right non-overlapping intervals
        while (i < n)
        {
            ans.push_back(intervals[i]);
            i++;
        }

        return ans;
    }
};

int main()
{
    Solution solution;

    vector<vector<int>> intervals1 = {{1, 3}, {6, 9}};
    vector<int> newInterval1 = {2, 5};
    vector<vector<int>> result1 = solution.insert(intervals1, newInterval1);

    cout << "Result 1: ";
    for (const auto &interval : result1)
    {
        cout << "[" << interval[0] << "," << interval[1] << "] ";
    }
    cout << endl;

    vector<vector<int>> intervals2 = {{1, 2}, {3, 5}, {6, 7}, {8, 10}, {12, 16}};
    vector<int> newInterval2 = {4, 8};
    vector<vector<int>> result2 = solution.insert(intervals2, newInterval2);

    cout << "Result 2: ";
    for (const auto &interval : result2)
    {
        cout << "[" << interval[0] << "," << interval[1] << "] ";
    }
    cout << endl;

    return 0;
}

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class Solution
{
    struct meeting
    {
        int start, end, pos;
    };

    static bool comparator(const meeting &m1, const meeting &m2)
    {
        if (m1.end < m2.end)
            return true;
        else if (m1.end > m2.end)
            return false;
        else
            return m1.pos < m2.pos;
    }

public:
    pair<int, vector<int>> findLongestChain(vector<vector<int>> &pairs)
    {
        int n = pairs.size();
        vector<meeting> meet(n);

        for (int i = 0; i < n; i++)
        {
            meet[i].start = pairs[i][0];
            meet[i].end = pairs[i][1];
            meet[i].pos = i + 1;
        }

        sort(meet.begin(), meet.end(), comparator);

        int lastMeet = meet[0].end, count = 0;
        vector<int> ans;
        for (int i = 1; i < n; i++)
        {
            if (meet[i].start > lastMeet)
            {
                count++;
                lastMeet = meet[i].end;
                ans.push_back(meet[i].pos);
            }
        }

        return {count, ans};
    }
};

int main()
{
    vector<vector<int>> pairs = {{-10, -8}, {8, 9}, {-5, 0}, {6, 10}, {-6, -4}, {1, 7}, {9, 10}, {-4, 7}};

    Solution sol;
    pair<int, vector<int>> result = sol.findLongestChain(pairs);

    cout << "The length of the longest chain is: " << result.first << endl;
    cout << "The meetings in the longest chain are: ";
    for (int pos : result.second)
    {
        cout << pos << " ";
    }
    cout << endl;

    return 0;
}

#include <iostream>
#include <vector>
#include <unordered_map>
#include <algorithm>
using namespace std;

class Solution
{
public:
    vector<vector<int>> findWinners(vector<vector<int>> &matches)
    {
        vector<vector<int>> ans;
        int n = matches.size();
        unordered_map<int, int> lost_map; // key: player, value: count of losses
        vector<int> notLost, lostOnce;

        for (int i = 0; i < n; i++)
        {
            int loser = matches[i][1];
            lost_map[loser]++;
        }

        for (int i = 0; i < n; i++)
        {
            int winner = matches[i][0];
            int loser = matches[i][1];

            if (lost_map.find(winner) == lost_map.end())
            {
                notLost.push_back(winner);
                lost_map[winner] = 2;
            }

            if (lost_map[loser] == 1)
            {
                lostOnce.push_back(loser);
            }
        }

        sort(notLost.begin(), notLost.end());
        sort(lostOnce.begin(), lostOnce.end());

        return {notLost, lostOnce};
    }
};

int main()
{
    int n;
    cout << "Enter the number of matches: ";
    cin >> n;

    vector<vector<int>> matches(n, vector<int>(2));
    cout << "Enter the matches (winner and loser pairs): " << endl;
    for (int i = 0; i < n; ++i)
    {
        cin >> matches[i][0] >> matches[i][1];
    }

    Solution sol;
    vector<vector<int>> result = sol.findWinners(matches);

    cout << "Players with no losses: ";
    for (int player : result[0])
    {
        cout << player << " ";
    }
    cout << endl;

    cout << "Players with one loss: ";
    for (int player : result[1])
    {
        cout << player << " ";
    }
    cout << endl;

    return 0;
}

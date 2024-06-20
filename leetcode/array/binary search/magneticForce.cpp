#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class Solution
{
public:
    bool isPossible(int force, vector<int> &position, int m)
    {
        int prev = position[0];
        int countBalls = 1;

        for (int i = 1; i < position.size(); i++)
        {
            int curr = position[i];

            if (curr - prev >= force)
            {
                countBalls++;
                prev = curr;
            }
            if (countBalls == m)
                break;
        }

        return (countBalls == m);
    }

    int maxDistance(vector<int> &position, int m)
    {
        int n = position.size();
        sort(position.begin(), position.end());
        int minForce = 1, maxForce = position[n - 1] - position[0];

        int ans = 0;
        while (minForce <= maxForce)
        {
            int mid = minForce + (maxForce - minForce) / 2;

            if (isPossible(mid, position, m))
            {
                ans = mid;
                minForce = mid + 1;
            }
            else
            {
                maxForce = mid - 1;
            }
        }

        return ans;
    }
};

int main()
{
    Solution sol;
    vector<int> position = {1, 2, 8, 4, 9};
    int m = 3;

    int result = sol.maxDistance(position, m);
    cout << "The maximum distance is: " << result << endl;

    return 0;
}

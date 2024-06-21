#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class Solution
{
public:
    int maxSatisfied(vector<int> &cust, vector<int> &grump, int mins)
    {

        int n = cust.size();
        int currUnsat = 0, maxUnsat = 0;

        for (int i = 0; i < mins; i++)
        {
            currUnsat += cust[i] * grump[i];
        }

        maxUnsat = currUnsat;
        int i = 0, j = mins;

        while (j < n)
        {
            currUnsat += cust[j] * grump[j]; // new element in the window
            currUnsat -= cust[i] * grump[i]; // removing element in the window

            maxUnsat = max(currUnsat, maxUnsat);

            i++, j++;
        }

        int ans = maxUnsat;
        for (int i = 0; i < n; i++)
        {
            if (grump[i] == 0)
            {
                ans += cust[i] * (1 - grump[i]);
            }
        }

        return ans;
    }
};

int main()
{
    Solution solution;

    vector<int> customers = {1, 0, 1, 2, 1, 1, 7, 5};
    vector<int> grumpy = {0, 1, 0, 1, 0, 1, 0, 1};
    int minutes = 3;

    int result = solution.maxSatisfied(customers, grumpy, minutes);
    cout << "Maximum number of satisfied customers: " << result << endl;

    return 0;
}

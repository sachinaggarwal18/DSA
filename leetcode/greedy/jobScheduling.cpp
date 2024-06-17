#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

struct Job
{
    int id, dead, profit;
};

class Solution
{
public:
    static bool comparator(Job j1, Job j2)
    {
        return j1.profit > j2.profit;
    }

    // Function to find the maximum profit and the number of jobs done.
    vector<int> JobScheduling(Job arr[], int n)
    {
        // Sorting jobs according to their profits in descending order.
        sort(arr, arr + n, comparator);

        // Finding the maximum deadline among all jobs.
        int max_deadline = 0;
        for (int i = 0; i < n; i++)
        {
            max_deadline = max(max_deadline, arr[i].dead);
        }

        // Making an array of size max_deadline+1 initialized with '-1'.
        vector<int> slot(max_deadline + 1, -1);

        int jobCount = 0, maxProfit = 0;

        // Iterating through all given jobs.
        for (int i = 0; i < n; i++)
        {
            // Finding a free slot for this job (starting from the last possible slot).
            for (int j = arr[i].dead; j > 0; j--)
            {
                if (slot[j] == -1)
                {
                    slot[j] = i;
                    jobCount++;
                    maxProfit += arr[i].profit;
                    break;
                }
            }
        }

        return {jobCount, maxProfit};
    }
};

int main()
{
    int n = 4;
    Job arr[] = {{1, 4, 20}, {2, 1, 10}, {3, 1, 40}, {4, 1, 30}};
    Solution ob;
    vector<int> ans = ob.JobScheduling(arr, n);
    cout << ans[0] << " " << ans[1] << endl;
    return 0;
}

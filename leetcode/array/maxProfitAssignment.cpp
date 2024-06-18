#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;

class Solution
{
public:
    int maxProfitAssignment(vector<int> &difficulty, vector<int> &profit,
                            vector<int> &worker)
    {

        int n = difficulty.size();
        int m = worker.size();
        sort(worker.begin(), worker.end(), greater<int>());

        priority_queue<pair<int, int>> pq;
        for (int i = 0; i < n; i++)
        {
            int diff = difficulty[i];
            int prof = profit[i];

            pq.push({diff, prof});
        }

        int i = 0, ans = 0;
        while (i < m && !pq.empty())
        {
            if (pq.top().first > worker[i])
            {
                pq.pop();
            }
            else
            {
                ans += pq.top().second;
                i++;
            }
        }

        return ans;
    }
};

int main()
{
    Solution solution;

    int n, m;

    cout << "Enter the number of jobs: ";
    cin >> n;

    vector<int> difficulty(n), profit(n);

    cout << "Enter the difficulty of each job: ";
    for (int i = 0; i < n; i++)
    {
        cin >> difficulty[i];
    }

    cout << "Enter the profit of each job: ";
    for (int i = 0; i < n; i++)
    {
        cin >> profit[i];
    }

    cout << "Enter the number of workers: ";
    cin >> m;

    vector<int> worker(m);

    cout << "Enter the skill level of each worker: ";
    for (int i = 0; i < m; i++)
    {
        cin >> worker[i];
    }

    int result = solution.maxProfitAssignment(difficulty, profit, worker);
    cout << "Maximum profit: " << result << endl;

    return 0;
}

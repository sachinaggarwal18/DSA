#include <iostream>
#include <vector>
#include <algorithm>
#include <climits>
using namespace std;

class Solution
{
public:
    bool solve(int days, vector<int> &bloomDay, int m, int k)
    {
        int cnt = 0, noOfBoq = 0;

        for (int i = 0; i < bloomDay.size(); i++)
        {
            if (bloomDay[i] <= days)
            {
                cnt++;
            }
            else
            {
                noOfBoq += (cnt / k);
                cnt = 0;
            }
        }
        noOfBoq += (cnt / k);

        return (noOfBoq >= m);
    }

    int minDays(vector<int> &bloomDay, int m, int k)
    {
        long long val = k * 1LL * m * 1LL;

        if (val > bloomDay.size())
            return -1;

        int maxi = INT_MIN, mini = INT_MAX;

        for (int i = 0; i < bloomDay.size(); i++)
        {
            maxi = max(maxi, bloomDay[i]);
            mini = min(mini, bloomDay[i]);
        }

        int low = mini, high = maxi;

        while (low <= high)
        {
            int mid = (high + low) / 2;

            if (solve(mid, bloomDay, m, k))
            {
                high = mid - 1;
            }
            else
            {
                low = mid + 1;
            }
        }

        return low;
    }
};

int main()
{
    int n, m, k;
    cout << "Enter the number of elements in bloomDay: ";
    cin >> n;
    vector<int> bloomDay(n);

    cout << "Enter the bloom days: ";
    for (int i = 0; i < n; i++)
    {
        cin >> bloomDay[i];
    }

    cout << "Enter the number of bouquets (m): ";
    cin >> m;

    cout << "Enter the number of flowers per bouquet (k): ";
    cin >> k;

    Solution sol;
    int result = sol.minDays(bloomDay, m, k);

    cout << "Minimum number of days: " << result << endl;

    return 0;
}

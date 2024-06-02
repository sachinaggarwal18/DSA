#include <iostream>
#include <vector>
using namespace std;

class Solution
{
public:
    bool f(int i, int n, int k, vector<int> &a)
    {

        if (k == 0)
        {
            return true;
        }

        if (i >= n || k < 0)
        {
            return false;
        }
        int take = 0, notTake = 0;

        notTake = f(i + 1, n, k, a);

        if (a[i] <= k)
        {
            take = f(i + 1, n, k - a[i], a);
        }
        return take || notTake;
    }
    bool subsetSumToK(int n, int k, vector<int> &arr)
    {

        return f(0, n, k, arr);
    }
};

int main()
{
    Solution obj;
    int n, k;
    cout << "Enter number of elements: " << endl;
    cin >> n;

    vector<int> arr(n);
    cout << "Enter elements: " << endl;

    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }
    cout << "Enter target: " << endl;
    cin >> k;

    if (obj.subsetSumToK(n, k, arr))
    {
        cout << "Subset with sum " << k << " exists." << endl;
    }
    else
    {
        cout << "Subset with sum " << k << " does not exists." << endl;
    }
    return 0;
}
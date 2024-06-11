#include <iostream>
#include <vector>
using namespace std;

class Solution
{
public:
    vector<int> relativeSortArray(vector<int> &arr1, vector<int> &arr2)
    {
        int maxi = INT_MIN;
        int n = arr1.size(), m = arr2.size();

        for (int i = 0; i < n; i++)
        {
            maxi = max(maxi, arr1[i]);
        }

        vector<int> freq(maxi), res;

        for (int i = 0; i < n; i++)
        {
            int element = arr1[i];
            freq[element]++;
        }

        for (int i = 0; i < m; i++)
        {
            int element = arr2[i];
            while (freq[element])
            {
                res.push_back(element);
                freq[element]--;
            }
        }

        // fill the remaining elements of vector<int> freq(maxi + 1);
        for (int i = 0; i < maxi + 1; i++)
        {
            int element = arr2[i];
            while (freq[i])
            {
                res.push_back(i);
                freq[i]--;
            }
        }

        return res;
    }
};

int main()
{

    int n, m;

    cout << "enter size of first array: " << endl;
    cin >> n;

    cout << "enter size of second array: " << endl;
    cin >> m;

    vector<int> arr1(n), arr2(m);

    cout << "enter elements of first array: " << endl;
    for (int i = 0; i < n; i++)
    {
        cin >> arr1[i];
    }

    cout << "enter elements of second array: " << endl;
    for (int i = 0; i < m; i++)
    {
        cin >> arr2[i];
    }

    Solution obj;

    vector<int> ans = obj.relativeSortArray(arr1, arr2);

    cout << "Sorted array: " << endl;
    for (int i = 0; i < ans.size(); i++)
    {
        cout << ans[i] << " ";
    }
    cout << endl;
}
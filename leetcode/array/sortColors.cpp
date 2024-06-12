#include <iostream>
#include <vector>
using namespace std;

class Solution
{
public:
    vector<int> sortColors(vector<int> &arr)
    {

        int c1 = 0, c2 = 0, c3 = 0, n = arr.size();
        for (int i = 0; i < n; i++)
        {
            if (arr[i] == 0)
            {
                c1++;
            }

            if (arr[i] == 1)
            {
                c2++;
            }

            if (arr[i] == 2)
            {
                c3++;
            }
        }

        for (int i = 0; i < c1; i++)
        {
            arr[i] = 0;
        }

        for (int i = c1; i < c1 + c2; i++)
        {
            arr[i] = 1;
        }

        for (int i = c1 + c2; i < n; i++)
        {
            arr[i] = 2;
        }

        return arr;
    }
};

int main()
{

    int n;
    Solution obj;
    cout << "Enter size of array- " << endl;
    cin >> n;
    vector<int> arr(n);

    cout << "Enter elements of array(only 0,1,2)- " << endl;
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }

    vector<int> ans = obj.sortColors(arr);
    cout << "Sorted Array- " << endl;
    for (int i = 0; i < ans.size(); i++)
    {
        cout << ans[i] << " ";
    }
}
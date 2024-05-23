#include <iostream>
#include <map>
using namespace std;

// storing,fetching-> log(n) in all cases

int main()
{
    int n;
    cout << "enter size of the array- " << endl;
    cin >> n;

    int arr[n];
    cout << "enter elements of the array-" << endl;
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }

    map<int, int> m; // <value, its frequency>
    for (int i = 0; i < n; i++)
    {
        m[arr[i]]++;
    }

    // iterate in the map
    for (auto it : m)
    {
        cout << it.first << "->" << it.second << endl;
    }

    int q;
    cout << "enter no. of queries- " << endl;
    cin >> q;
    while (q--)
    {
        int number;
        cin >> number;

        // fetching
        cout << m[number] << endl;
    }
}
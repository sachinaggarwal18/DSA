#include <iostream>
using namespace std;
// prestore something and fetch when required

// max size of array we can declare inside main= arr[10^6] (for int)   bool-1e7
// max size of array we can declare globally = near about arr[10^7] (for int)   bool-1e8

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

    // precomutation
    int hash[13] = {0}; // initally al 13 elements are initialized with '0'
    for (int i = 0; i < n; i++)
    {
        hash[arr[i]] += 1;
    }

    int q;
    cout << "enter no. of queries- " << endl;
    cin >> q;

    while (q--)
    {
        int number;
        cin >> number;

        // fetching
        cout << hash[number] << endl;
    }

    return 0;
}
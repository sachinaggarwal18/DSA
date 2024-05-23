#include <iostream>
using namespace std;

int main()
{
    string s;
    cout << "enter a string- " << endl;
    cin >> s;

    // precomutation
    int hash[26] = {0};
    for (int i = 0; i < s.size(); i++)
    {
        hash[s[i] - 'a'] += 1;
    }

    int q;
    cout << "enter no. of queries- " << endl;
    cin >> q;

    while (q--)
    {
        char c;
        cin >> c;

        // fetching
        cout << hash[c - 'a'] << endl;
    }

    return 0;
}
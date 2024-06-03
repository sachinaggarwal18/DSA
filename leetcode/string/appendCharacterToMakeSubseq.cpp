#include <string>
#include <iostream>
using namespace std;

class Solution
{
public:
    int appendCharacters(string s, string t)
    {

        int i = 0, j = 0;
        int n = s.length();
        int m = t.length();

        while (i < n && j < m)
        {
            if (s[i] == t[j])
            {
                i++, j++;
            }
            else
            {
                i++;
            }
        }

        return (m - j);
    }
};

int main()
{
    Solution obj;

    string s, t;
    cout << "Enter first string: " << endl;
    cin >> s;

    cout << "Enter second string: " << endl;
    cin >> t;

    int ans = obj.appendCharacters(s, t);
    cout << "Ans: " << ans;
}
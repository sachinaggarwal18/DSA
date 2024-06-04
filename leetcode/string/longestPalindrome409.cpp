#include <string>
#include <iostream>
using namespace std;
class Solution
{
public:
    int longestPalindrome(string s)
    {

        unordered_map<char, int> mpp;

        for (char it : s)
        {
            mpp[it]++;
        }

        int ans = 0;
        bool flag = false;

        for (auto &p : mpp)
        {
            if (p.second % 2 == 0)
            {
                ans += p.second;
            }
            else
            {
                ans += p.second - 1;
                flag = true;
            }
        }

        if (flag == true)
        {
            ans += 1;
        }

        return ans;
    }
};

int main()
{
    Solution obj;

    string str;
    cout << "Enter a string: " << endl;
    cin >> str;

    int ans = obj.longestPalindrome(str);
    cout << "Ans: " << ans;
}
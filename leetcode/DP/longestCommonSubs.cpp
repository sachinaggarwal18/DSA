#include <iostream>
#include <vector>
#include <string>
using namespace std;

class Solution
{
public:
    int solve(string &s1, string &s2, int i, int j)
    {
        if (i >= s1.length() || j >= s2.length())
        {
            return 0;
        }

        if (s1[i] == s2[j])
        {
            return 1 + solve(s1, s2, i + 1, j + 1);
        }
        else
        {
            return max(solve(s1, s2, i + 1, j), solve(s1, s2, i, j + 1));
        }
    }

    int longestCommonSubsequence(string text1, string text2)
    {
        return solve(text1, text2, 0, 0);
    }
};

int main()
{
    Solution sol;

    string text1, text2;
    cout << "Enter the first string: ";
    cin >> text1;
    cout << "Enter the second string: ";
    cin >> text2;

    int lcsLength = sol.longestCommonSubsequence(text1, text2);
    cout << "The length of the longest common subsequence is: " << lcsLength << endl;

    return 0;
}

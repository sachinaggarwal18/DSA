#include <iostream>
#include <string>
#include <unordered_map>
#include <algorithm>

class Solution
{
public:
    int characterReplacement(std::string s, int k)
    {
        std::unordered_map<char, int> mp;
        int n = s.length(), l = 0, r = 0, maxFreq = 0, ans = 0;

        while (r < n)
        {
            mp[s[r]]++;
            maxFreq = std::max(maxFreq, mp[s[r]]);

            // If the number of characters to be replaced is more than k, shrink the window
            if ((r - l + 1) - maxFreq > k)
            {
                mp[s[l]]--;
                l++;
            }

            ans = std::max(ans, r - l + 1);
            r++;
        }
        return ans;
    }
};

int main()
{
    Solution solution;

    std::string s1 = "ABAB";
    int k1 = 2;
    std::cout << "Longest substring length for s1: " << solution.characterReplacement(s1, k1) << std::endl; // Output: 4

    std::string s2 = "AABABBA";
    int k2 = 1;
    std::cout << "Longest substring length for s2: " << solution.characterReplacement(s2, k2) << std::endl; // Output: 4

    return 0;
}
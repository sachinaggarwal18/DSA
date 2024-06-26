#include <string>
#include <unordered_set>
#include <algorithm>
#include <iostream>
using namespace std;

class Solution
{
public:
    int lengthOfLongestSubstring(std::string s)
    {
        int n = s.length();
        if (n == 0)
            return 0; // If string is empty, longest substring length is 0

        std::unordered_set<char> seen;
        int left = 0, right = 0, cnt = 0;

        while (right < n)
        {
            // Expand the window to the right
            while (right < n && seen.find(s[right]) == seen.end())
            {
                seen.insert(s[right]);
                cnt = std::max(cnt, right - left + 1);
                right++;
            }

            // Shrink the window from the left
            seen.erase(s[left]);
            left++;
        }

        return cnt;
    }
};

int main()
{
    Solution sol;
    std::string s1 = "abcabcbb";
    std::cout << "Length of longest substring without repeating characters: " << sol.lengthOfLongestSubstring(s1) << std::endl;

    std::string s2 = "bbbbb";
    std::cout << "Length of longest substring without repeating characters: " << sol.lengthOfLongestSubstring(s2) << std::endl;

    std::string s3 = "pwwkew";
    std::cout << "Length of longest substring without repeating characters: " << sol.lengthOfLongestSubstring(s3) << std::endl;

    return 0;
}
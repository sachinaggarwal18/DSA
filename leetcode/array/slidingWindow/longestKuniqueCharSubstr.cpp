#include <iostream>
#include <vector>
#include <unordered_map>
#include <algorithm>

class Solution
{
public:
    int longestKSubstr(std::string s, int k)
    {
        std::unordered_map<char, int> mp;
        int n = s.size(), l = 0, r = 0, ans = -1; // Initialize ans to -1 to handle cases where there is no valid substring

        while (r < n)
        {
            mp[s[r]]++;

            while (mp.size() > k)
            {
                mp[s[l]]--;
                if (mp[s[l]] == 0)
                {
                    mp.erase(s[l]);
                }
                l++;
            }

            if (mp.size() == k)
            {
                ans = std::max(ans, r - l + 1);
            }
            r++;
        }
        return ans;
    }
};

int main()
{
    Solution solution;

    // Test case 1
    std::string s1 = "aabacbebebe";
    int k1 = 3;
    std::cout << "Longest substring length with " << k1 << " unique characters: " << solution.longestKSubstr(s1, k1) << std::endl; // Output: 7

    // Test case 2
    std::string s2 = "aaaa";
    int k2 = 2;
    std::cout << "Longest substring length with " << k2 << " unique characters: " << solution.longestKSubstr(s2, k2) << std::endl; // Output: -1

    return 0;
}
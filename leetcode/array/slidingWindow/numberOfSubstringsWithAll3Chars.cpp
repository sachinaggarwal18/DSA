#include <iostream>
#include <unordered_map>
#include <algorithm>

class Solution
{
public:
    int numberOfSubstrings(std::string s)
    {
        int n = s.length(), cnt = 0;
        std::unordered_map<int, int> mp;
        mp[0] = -1;
        mp[1] = -1;
        mp[2] = -1;

        for (int i = 0; i < n; i++)
        {
            mp[s[i] - 'a'] = i;

            if (mp[0] != -1 && mp[1] != -1 && mp[2] != -1)
            {
                int mini = std::min({mp[0], mp[1], mp[2]});
                cnt += mini + 1;
            }
        }
        return cnt;
    }
};

int main()
{
    Solution solution;

    std::string s1 = "abcabc";
    std::cout << "Number of substrings for s1: " << solution.numberOfSubstrings(s1) << std::endl; // Output: 10

    std::string s2 = "aaacb";
    std::cout << "Number of substrings for s2: " << solution.numberOfSubstrings(s2) << std::endl; // Output: 3

    std::string s3 = "abc";
    std::cout << "Number of substrings for s3: " << solution.numberOfSubstrings(s3) << std::endl; // Output: 1

    return 0;
}
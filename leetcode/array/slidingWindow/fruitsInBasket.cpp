#include <iostream>
#include <vector>
#include <unordered_map>
#include <algorithm>

class Solution
{
public:
    int totalFruit(std::vector<int> &fruits)
    {
        std::unordered_map<int, int> mp;
        int n = fruits.size(), l = 0, r = 0, ans = 0;

        while (r < n)
        {
            mp[fruits[r]]++;

            while (mp.size() > 2)
            {
                mp[fruits[l]]--;

                if (mp[fruits[l]] == 0)
                    mp.erase(fruits[l]);
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

    // Test case 1
    std::vector<int> fruits1 = {1, 2, 1};
    std::cout << "Total fruits for test case 1: " << solution.totalFruit(fruits1) << std::endl; // Output: 3

    // Test case 2
    std::vector<int> fruits2 = {0, 1, 2, 2};
    std::cout << "Total fruits for test case 2: " << solution.totalFruit(fruits2) << std::endl; // Output: 3

    // Test case 3
    std::vector<int> fruits3 = {1, 2, 3, 2, 2};
    std::cout << "Total fruits for test case 3: " << solution.totalFruit(fruits3) << std::endl; // Output: 4

    // Test case 4
    std::vector<int> fruits4 = {3, 3, 3, 1, 2, 1, 1, 2, 3, 3, 4};
    std::cout << "Total fruits for test case 4: " << solution.totalFruit(fruits4) << std::endl; // Output: 5

    return 0;
}
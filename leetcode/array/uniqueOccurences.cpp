#include <iostream>
#include <vector>
#include <unordered_map>
#include <unordered_set>

class Solution
{
public:
    bool uniqueOccurrences(std::vector<int> &arr)
    {
        std::unordered_map<int, int> mp;
        std::unordered_set<int> st;

        for (int i : arr)
        {
            mp[i]++;
        }

        for (const auto &pair : mp)
        {
            if (st.find(pair.second) != st.end())
            {
                return false;
            }
            else
            {
                st.insert(pair.second);
            }
        }
        return true;
    }
};

int main()
{
    Solution solution;
    std::vector<int> arr1 = {1, 2, 2, 1, 1, 3};
    std::vector<int> arr2 = {1, 2};
    std::vector<int> arr3 = {-3, 0, 1, -3, 1, 1, 1, -3, 10, 0};

    std::cout << std::boolalpha << solution.uniqueOccurrences(arr1) << std::endl; // true
    std::cout << std::boolalpha << solution.uniqueOccurrences(arr2) << std::endl; // false
    std::cout << std::boolalpha << solution.uniqueOccurrences(arr3) << std::endl; // true

    return 0;
}

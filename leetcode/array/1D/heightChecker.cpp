#include <iostream>
#include <vector>
#include <algorithm>

class Solution
{
public:
    int heightChecker(std::vector<int> &heights)
    {
        int n = heights.size(), ans = 0;
        std::vector<int> expected(heights); // Use the copy constructor to initialize expected with heights

        std::sort(expected.begin(), expected.end()); // Sort the expected array

        int i = 0, j = 0;

        while (i < n && j < n)
        { // Modified to '&&' to ensure valid index access
            if (heights[i++] != expected[j++])
            {
                ans++;
            }
        }

        return ans;
    }
};

int main()
{
    Solution solution;
    int n;

    std::cout << "Enter the number of students: ";
    std::cin >> n;

    std::vector<int> heights(n);
    std::cout << "Enter the heights of the students: ";
    for (int i = 0; i < n; ++i)
    {
        std::cin >> heights[i];
    }

    int result = solution.heightChecker(heights);
    std::cout << "Number of indices where heights do not match the expected order: " << result << std::endl;

    return 0;
}

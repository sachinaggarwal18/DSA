#include <iostream>
#include <vector>
using namespace std;

class Solution
{
public:
    int sumOddLengthSubarrays(vector<int> &arr)
    {
        int n = arr.size();
        int totalSum = 0;

        // Iterate through each element in the array
        for (int i = 0; i < n; ++i)
        {
            int subarraySum = 0;
            // Iterate through subarrays starting from i with odd lengths
            for (int j = i; j < n; ++j)
            {
                subarraySum += arr[j];
                if ((j - i) % 2 == 0)
                { // Only consider subarrays of odd length
                    totalSum += subarraySum;
                }
            }
        }

        return totalSum;
    }
};

int main()
{
    Solution sol;
    int n;

    // Take input for array size
    cout << "Enter the number of elements in the array: ";
    cin >> n;

    // Take input for array elements
    vector<int> arr(n);
    cout << "Enter the elements of the array: ";
    for (int i = 0; i < n; ++i)
    {
        cin >> arr[i];
    }

    // Calculate and print the result
    int result = sol.sumOddLengthSubarrays(arr);
    cout << "The sum of all possible odd-length subarrays is: " << result << endl;

    return 0;
}

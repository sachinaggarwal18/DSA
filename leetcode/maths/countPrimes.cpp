#include <iostream>
#include <vector>
using namespace std;

class Solution
{
public:
    int sieveOfEratosthenes(int n)
    {
        vector<int> temp(n, 1); // Initialize all entries as 1 (true)
        int cnt = 0;

        for (int i = 2; i * i < n; i++)
        {
            if (temp[i] == 1)
            {
                for (int j = i * i; j < n; j += i)
                {
                    temp[j] = 0; // Mark multiples of i as 0 (false)
                }
            }
        }

        for (int i = 2; i < n; i++)
        {
            if (temp[i] == 1)
            {
                cnt++;
            }
        }

        return cnt;
    }

    int countPrimes(int n)
    {
        if (n <= 2)
        {
            return 0;
        }
        return sieveOfEratosthenes(n);
    }
};

int main()
{
    Solution sol;
    int n;

    cout << "Enter a number: ";
    cin >> n;

    int result = sol.countPrimes(n);
    cout << "Number of prime numbers less than " << n << " is: " << result << endl;

    return 0;
}
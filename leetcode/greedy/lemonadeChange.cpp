#include <iostream>
#include <vector>
using namespace std;

class Solution
{
public:
    bool lemonadeChange(vector<int> &bills)
    {
        int five = 0, ten = 0;

        for (int bill : bills)
        {
            if (bill == 5)
            {
                five += 1;
            }
            else if (bill == 10)
            {
                if (five)
                {
                    return false;
                }
                else
                {
                    five -= 1;
                    ten += 1;
                }
            }
            else // we got 20
            {
                if (five && ten)
                {
                    five -= 1;
                    ten -= 1;
                }
                else if (five >= 3)
                {
                    five -= 3;
                }
                else
                {
                    return false;
                }
            }
        }
        return true;
    }
};

int main()
{
    int n;
    cout << "Enter the number of customers: ";
    cin >> n;

    vector<int> bills(n);
    cout << "Enter the bills: ";
    for (int i = 0; i < n; i++)
    {
        cin >> bills[i];
    }

    Solution solution;
    bool result = solution.lemonadeChange(bills);

    if (result)
    {
        cout << "true" << endl;
    }
    else
    {
        cout << "false" << endl;
    }

    return 0;
}

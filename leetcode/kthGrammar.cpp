#include <iostream>

using namespace std;
class Solution
{
public:
    int kthGrammar(int n, int k)
    {

        if (n == 1 && k == 1)
        {
            return 0;
        }

        int length = 1 << (n - 1);
        int mid = length / 2;

        if (k <= mid)
        {
            return kthGrammar(n - 1, k);
        }

        return !kthGrammar(n - 1, k - mid);
    }
};

int main()
{

    Solution obj;

    int n, k;

    cout << "Enter value of n: " << endl;
    cin >> n;

    cout << "Enter value of k: " << endl;
    cin >> k;

    int ans = obj.kthGrammar(n, k);
    cout << "Ans: " << ans << endl;
}
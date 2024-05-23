#include <string.h>
#include <iostream>
using namespace std;

int power(int a, int b)
{

    // base case
    if (b == 0)
        return 1;

    if (b == 1)
        return a;

    // recursive call

    long long ans = power(a, b / 2);

    // if b is even
    if (b % 2 == 0)
    {
        return ans * ans;
    }
    else
    {
        return a * ans * ans;
    }
}

int main()
{
    int a, b;
    cout << " enter value of a - ";
    cin >> a;

    cout << " enter value of b - ";
    cin >> b;

    long long ans = power(a, b);

    cout << "answer is " << ans << endl;
}

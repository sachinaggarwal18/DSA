#include <string.h>
#include <iostream>
using namespace std;

void sayDigit(int n, string arr[])
{
    if (n == 0)
        return;

    int digit = n % 10;
    n = n / 10;
    cout << arr[n] << " ";
}

int main()
{
    string arr[10] = {"one", "two", "three", "four", "five", "six", "seven", "eight", "nine"};

    int n;
    cin >> n;

    sayDigit(n, arr);
}
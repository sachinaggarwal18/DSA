#include <string.h>
#include <iostream>
using namespace std;

bool check(string &str, int len, int i, int j)
{

    if (i > j)
    {
        return true;
    }

    if (str[i] != str[j])
    {
        return false;
    }
    else
    {
        return check(str, len, i + 1, j - 1);
    }
}

int main()
{

    string str = "hi";

    bool ans = check(str, str.length(), 0, str.length() - 1);
    if (ans)
    {
        cout << "palindrome";
    }
    else
    {
        cout << "not palindrome";
    }

    return 0;
}
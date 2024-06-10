#include <vector>
#include <iostream>
using namespace std;

class Solution
{
public:
    vector<string> res;

    bool isValid(string str)
    {
        int count = 0;
        for (int i = 0; i < str.length(); i++)
        {
            if (str[i] == '(')
            {
                count++;
            }
            else if (str[i] == ')')
            {
                count--;
            }
            if (count < 0)
            {
                return false;
            }
        }
        return count == 0;
    }

    void generateParanthesis(string curr, int n)
    {
        if (curr.size() == n * 2)
        {
            if (isValid(curr))
            {
                res.push_back(curr);
            }
            return;
        }

        curr.push_back('(');
        generateParanthesis(curr, n);
        curr.pop_back();

        curr.push_back(')');
        generateParanthesis(curr, n);
        curr.pop_back();
    }

    vector<string> getParanthesis(int n)
    {
        string curr = "";
        generateParanthesis(curr, n);
        return res;
    }
};

int main()
{
    int n;
    cout << "Enter value of n: ";
    cin >> n;
    Solution obj;
    vector<string> ans = obj.getParanthesis(n);

    cout << "Ans: ";
    for (const string &s : ans)
    {
        cout << s << " ";
    }
    cout << endl;
    return 0;
}

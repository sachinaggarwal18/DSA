#include <iostream>
#include <stack>

using namespace std;

void reverse()
{
    //    string s;

    // Take input using cin
    string str;
    cout << "Enter a string: " << endl;
    cin >> str;
    stack<char> st;
    string ans = "";

    for (int i = 0; i < str.length(); i++) // pushing into stack
    {
        st.push(str[i]);
    }

    while (!st.empty()) // popping from stack
    {
        // char c = st.top();
        ans.push_back(st.top());
        st.pop();
    }

    cout << ans << endl;
}

int main()
{
    reverse();
}
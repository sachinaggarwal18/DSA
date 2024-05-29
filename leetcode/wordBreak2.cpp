#include <iostream>
#include <vector>
#include <string>
#include <unordered_set>

using namespace std;

class Solution
{
public:
    vector<string> res;
    unordered_set<string> st;

    void solve(int ind, string currSentence, string s)
    {
        if (ind >= s.length())
        {
            res.push_back(currSentence);
            return;
        }

        for (int j = ind; j < s.length(); j++)
        {
            string tempWord = s.substr(ind, j - ind + 1);
            if (st.count(tempWord))
            {
                string tempSentence = currSentence;
                if (!currSentence.empty())
                {
                    currSentence += " ";
                }
                currSentence += tempWord;      // take
                solve(j + 1, currSentence, s); // recursion
                currSentence = tempSentence;   // remove
            }
        }
    }

    vector<string> wordBreak(string s, vector<string> &wordDict)
    {
        for (string &word : wordDict)
        {
            st.insert(word);
        }
        string currSentence = "";
        solve(0, currSentence, s);
        return res;
    }
};

int main()
{
    Solution solution;

    // Example 1
    string s1 = "catsanddog";
    vector<string> wordDict1 = {"cat", "cats", "and", "sand", "dog"};
    vector<string> result1 = solution.wordBreak(s1, wordDict1);
    cout << "Example 1 Output: ";
    for (const string &sentence : result1)
    {
        cout << sentence << endl;
    }

    // Example 2
    string s2 = "pineapplepenapple";
    vector<string> wordDict2 = {"apple", "pen", "applepen", "pine", "pineapple"};
    vector<string> result2 = solution.wordBreak(s2, wordDict2);
    cout << "Example 2 Output: ";
    for (const string &sentence : result2)
    {
        cout << sentence << endl;
    }

    // Example 3
    string s3 = "catsandog";
    vector<string> wordDict3 = {"cats", "dog", "sand", "and", "cat"};
    vector<string> result3 = solution.wordBreak(s3, wordDict3);
    cout << "Example 3 Output: ";
    for (const string &sentence : result3)
    {
        cout << sentence << endl;
    }

    return 0;
}

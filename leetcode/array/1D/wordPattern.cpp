#include <iostream>
#include <vector>
#include <unordered_map>
#include <unordered_set>
#include <sstream>
using namespace std;

class Solution
{
public:
    bool wordPattern(string pattern, string s)
    {

        string token;
        stringstream ss(s);
        vector<string> words;
        int countOfWords;

        while (ss >> token)
        {
            words.push_back(token);
            countOfWords++;
        }

        if (pattern.length() != countOfWords)
        {
            return false;
        }

        unordered_map<string, char> mp;
        unordered_set<char> used;

        for (int i = 0; i < pattern.length(); i++)
        {
            string word = words[i];
            char ch = pattern[i];

            if (mp.find(word) == mp.end() && used.find(ch) == used.end())
            {
                used.insert(ch);
                mp[word] = ch;
            }
            else if (mp[word] != pattern[i])
            {
                return false;
            }
        }
        return true;
    }
};

int main()
{
    string pattern = "abba";
    string s = "dog cat cat fish";

    Solution obj;
    bool ans = obj.wordPattern(pattern, s);

    ans == 1 ? cout << "true" : cout << "false";
}

#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <climits>

using namespace std;

class Solution
{
public:
    int maxScore;
    int n;

    void solve(int i, int currScore, vector<string> &words, vector<int> &score, vector<int> &freq)
    {
        maxScore = max(maxScore, currScore);
        if (i >= n)
        {
            return;
        }

        // can we even take this words[i]
        int j = 0, tempScore = 0;
        vector<int> tempFreq = freq;
        while (j < words[i].length())
        {
            char ch = words[i][j];
            tempFreq[ch - 'a']--;
            tempScore += score[ch - 'a'];
            if (tempFreq[ch - 'a'] < 0)
            {
                break;
            }
            j++;
        }

        if (j == words[i].length())
        { // we were able to form the word
            // take
            solve(i + 1, currScore + tempScore, words, score, tempFreq);
        }

        // notTake
        solve(i + 1, currScore, words, score, freq);
    }

    int maxScoreWords(vector<string> &words, vector<char> &letters, vector<int> &score)
    {
        n = words.size();
        vector<int> freq(26, 0);
        maxScore = INT_MIN;
        for (char &ch : letters)
        {
            freq[ch - 'a']++;
        }

        solve(0, 0, words, score, freq);
        return maxScore;
    }
};

int main()
{
    Solution solution;

    // Example 1
    vector<string> words1 = {"dog", "cat", "dad", "good"};
    vector<char> letters1 = {'a', 'a', 'c', 'd', 'd', 'd', 'g', 'o', 'o'};
    vector<int> score1 = {1, 0, 9, 5, 0, 0, 3, 0, 0, 0, 0, 0, 0, 0, 2, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0};
    cout << "Example 1 Output: " << solution.maxScoreWords(words1, letters1, score1) << endl; // Output: 23

    // Example 2
    vector<string> words2 = {"xxxz", "ax", "bx", "cx"};
    vector<char> letters2 = {'z', 'a', 'b', 'c', 'x', 'x', 'x'};
    vector<int> score2 = {4, 4, 4, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 5, 0, 10};
    cout << "Example 2 Output: " << solution.maxScoreWords(words2, letters2, score2) << endl; // Output: 27

    // Example 3
    vector<string> words3 = {"leetcode"};
    vector<char> letters3 = {'l', 'e', 't', 'c', 'o', 'd'};
    vector<int> score3 = {0, 0, 1, 1, 1, 0, 0, 0, 0, 0, 0, 1, 0, 0, 1, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0};
    cout << "Example 3 Output: " << solution.maxScoreWords(words3, letters3, score3) << endl; // Output: 0

    return 0;
}

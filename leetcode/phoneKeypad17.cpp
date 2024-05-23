#include <iostream>
#include <vector>
#include <string>

using namespace std;

class Solution {
public:
    vector<string> ans;
    string output = "";

    void solve(string digits, int index, string mapping[]) {
        if (index >= digits.size()) {
            ans.push_back(output);
            return;
        }

        int num = digits[index] - '0';
        string value = mapping[num];

        for (int i = 0; i < value.length(); i++) {
            output.push_back(value[i]);
            solve(digits, index + 1, mapping);
            output.pop_back();
        }
    }

    vector<string> letterCombinations(string digits) {
        string mapping[10] = {"",    "",    "abc",  "def", "ghi",
                              "jkl", "mno", "pqrs", "tuv", "wxyz"};

        ans.clear();  // Clear previous results
        output.clear();  // Clear previous output

        if (digits.size() == 0)
            return ans;

        solve(digits, 0, mapping);
        return ans;
    }
};

int main() {
    Solution obj;
    string digits = "23";
    vector<string> result = obj.letterCombinations(digits);

    cout << "Letter combinations for \"" << digits << "\":" << endl;
    for (const string& combination : result) {
        cout << combination << " ";
    }
    cout << endl;

    return 0;
}

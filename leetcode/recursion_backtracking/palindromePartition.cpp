#include <iostream>
#include <vector>
#include <string>
using namespace std;

class Solution{
    public:
    vector<vector<string>> ans;
    vector<string> curr;

bool isPalindrome(string s,int l,int r){

    while(l<r){
        if(s[l]!=s[r]){
            return false;
        }
        l++,r--;
    }
    return true;

}

void solve(string s,int ind,int n){

    if(ind==n){
        ans.push_back(curr);
        return;
    }

    for(int i=ind;i<n;i++){
        if(isPalindrome(s,ind,i)){
            curr.push_back(s.substr(ind,i-ind+1));
            solve(s,i+1,n);
             curr.pop_back();
        }
    }
}
};

int main() {
    string s = "abba";
    Solution obj;

    obj.solve(s, 0, s.length());

    // Print the results
    for (const auto& partition : obj.ans) {
        for (const auto& part : partition) {
            cout << part << " ";
        }
        cout << endl;
    }

    return 0;
}

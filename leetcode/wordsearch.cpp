#include <iostream>
#include <vector>
#include <string>
using namespace std;

class Solution {
public:
bool find(vector<vector<char>>& board,string word,int i,int j,int ind){

    int m=board.size();
    int n=board[0].size();

    if(ind==word.length()){
        return true;
    }

    if(i<0||j<0||i>=m||j>=n||board[i][j]=='$'||board[i][j]!=word[ind]){
        return false;
    }

    char temp=board[i][j];
    board[i][j]='$';

    bool found=find(board,word, i+1, j, ind+1)||find(board,word, i, j+1, ind+1)||
    find(board,word, i-1, j, ind+1)||find(board,word, i, j-1, ind+1);

  board[i][j]= temp;

  return found;
}

    bool solve(vector<vector<char>>& board, string word,int m,int n){

        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(board[i][j]==word[0] && find(board,word,i,j,0)){
                    return true;
                }
            }
        }
          return false;
    }
};

int main(){

 vector<vector<char>> board = {{'A', 'B', 'C', 'E'},
                                  {'S', 'F', 'C', 'S'},
                                  {'A', 'D', 'E', 'E'}};
    string word="SEE";
    int m=board.size();
    int n=board[0].size();

    Solution obj;
    bool ans=obj.solve(board,word,m, n);
    cout<< (ans?"true":"false")<<endl;
}

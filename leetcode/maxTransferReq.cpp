// #include <iostream>
// #include <vector>
// using namespace std;

// class Solution
// {
// public:
//     int m, res = 0;
//     void solve(int n, vector<vector<int>> &requests, vector<int> &resultant,
//                int ind, int count)
//     {
//         if (ind >= m)
//         {
//             bool flag = true;
//             for (int &x : resultant)
//             {
//                 if (x != 0)
//                 {
//                     flag = false;
//                     break;
//                 }
//             }
//             if (flag == true)
//             {
//                 res = max(res, count);
//             }
//             return;
//         }
//         int from = requests[ind][0];
//         int to = requests[ind][1];
//         resultant[from]--;
//         resultant[to]++;
//         solve(n, requests, resultant, ind + 1, count + 1);
//         resultant[from]++;
//         resultant[to]--;
//         solve(n, requests, resultant, ind + 1, count);
//     }

//     int maximumRequests(int n, vector<vector<int>> &requests)
//     {
//         m = requests.size();
//         vector<int> resultant(n, 0);
//         solve(n, requests, resultant, 0, 0);
//         return res;
//     }
// };

// int main()
// {
//     Solution solution;

//     vector<vector<int>> requests1 = {{0, 1}, {1, 0}, {0, 1}, {1, 2}, {2, 0}, {3, 4}};
//     int n1 = 5;
//     cout << "Example 1: " << solution.maximumRequests(n1, requests1) << endl;

//     vector<vector<int>> requests2 = {{0, 0}, {1, 2}, {2, 1}};
//     int n2 = 3;
//     cout << "Example 2: " << solution.maximumRequests(n2, requests2) << endl;

//     vector<vector<int>> requests3 = {{0, 3}, {3, 1}, {1, 2}, {2, 0}};
//     int n3 = 4;
//     cout << "Example 3: " << solution.maximumRequests(n3, requests3) << endl;

//     return 0;
// }

#include <iostream>
#include <vector>
using namespace std;

class Solution
{
public:
    int m, res;
    void solve(int n, vector<vector<int>> &requests, vector<int> &resultant,
               int ind, int count)
    {
        if (ind >= m)
        {
            bool flag = true;
            for (int &x : resultant)
            {
                if (x != 0)
                {
                    flag = false;
                    break;
                }
            }
            if (flag == true)
            {
                res = max(res, count);
            }
            return;
        }
        int from = requests[ind][0];
        int to = requests[ind][1];
        resultant[from]--;
        resultant[to]++;
        solve(n, requests, resultant, ind + 1, count + 1);
        resultant[from]++;
        resultant[to]--;
        solve(n, requests, resultant, ind + 1, count);
    }

    int maximumRequests(int n, vector<vector<int>> &requests)
    {
        res = 0; // Reset res for each call to maximumRequests
        m = requests.size();
        vector<int> resultant(n, 0);
        solve(n, requests, resultant, 0, 0);
        return res;
    }
};

int main()
{
    Solution solution;

    vector<vector<int>> requests1 = {{0, 1}, {1, 0}, {0, 1}, {1, 2}, {2, 0}, {3, 4}};
    int n1 = 5;
    cout << "Example 1: " << solution.maximumRequests(n1, requests1) << endl;

    vector<vector<int>> requests2 = {{0, 0}, {1, 2}, {2, 1}};
    int n2 = 3;
    cout << "Example 2: " << solution.maximumRequests(n2, requests2) << endl;

    vector<vector<int>> requests3 = {{0, 3}, {3, 1}, {1, 2}, {2, 0}};
    int n3 = 4;
    cout << "Example 3: " << solution.maximumRequests(n3, requests3) << endl;

    vector<vector<int>> requests4 = {{1, 3}, {2, 3}, {3, 3}, {0, 3}, {3, 1}, {1, 2}, {2, 0}};
    int n4 = 6;
    cout << "Example 4: " << solution.maximumRequests(n4, requests3) << endl;
    return 0;
}

#include <vector>
#include <algorithm>
#include <climits>
#include <iostream>
using namespace std;

class Solution
{
public:
    int maxScore(vector<int> &cardPoints, int k)
    {
        int n = cardPoints.size();
        int lsum = 0, rsum = 0, rIndex = n - 1;
        int maxi = INT_MIN;

        for (int i = 0; i < k; i++)
        {
            lsum += cardPoints[i];
        }

        maxi = lsum;

        for (int i = k - 1; i >= 0; i--)
        {
            lsum -= cardPoints[i];
            rsum += cardPoints[rIndex];
            rIndex--;

            maxi = max(maxi, lsum + rsum);
        }

        return maxi;
    }
};

int main()
{
    Solution sol;
    vector<int> cardPoints1 = {1, 2, 3, 4, 5, 6, 1};
    int k1 = 3;
    cout << sol.maxScore(cardPoints1, k1) << endl;

    vector<int> cardPoints2 = {2, 2, 2};
    int k2 = 2;
    cout << sol.maxScore(cardPoints2, k2) << endl;

    vector<int> cardPoints3 = {9, 7, 7, 9, 7, 7, 9};
    int k3 = 7;
    cout << sol.maxScore(cardPoints3, k3) << endl;

    return 0;
}
#include <iostream>
#include <string>
using namespace std;

// Definition for a binary tree node.
struct TreeNode
{
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution
{
public:
    string tree2str(TreeNode *root)
    {
        if (!root)
            return "";

        string result = to_string(root->val);

        if (root->left || root->right)
        {
            result += "(" + tree2str(root->left) + ")";
        }
        if (root->right)
        {
            result += "(" + tree2str(root->right) + ")";
        }

        return result;
    }
};

void testTree2Str()
{

    TreeNode *root = new TreeNode(1);
    root->left = new TreeNode(2);
    root->left->right = new TreeNode(4);
    root->right = new TreeNode(3);

    Solution sol;
    string result = sol.tree2str(root);

    cout << "The tree representation is: " << result << endl;

    // Cleaning up the allocated nodes
    delete root->left->right;
    delete root->left;
    delete root->right;
    delete root;
}

int main()
{
    testTree2Str();
    return 0;
}

#include <iostream>
using namespace std;
struct TreeNode
{
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

class Solution
{
public:
    int result;
    int kthSmallest(TreeNode *root, int k)
    {
        traverse(root, k);
        return result;
    }

    void traverse(TreeNode *node, int k)
    {
        if (!node)
            return;
        traverse(node->left, k);
        if (k == 1)
        {
            result = node->val;
            return;
        }
        --k;
        traverse(node->right, k);
    }
};
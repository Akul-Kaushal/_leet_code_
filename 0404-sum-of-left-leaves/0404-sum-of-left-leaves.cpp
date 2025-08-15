/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left),
 * right(right) {}
 * };
 */
class Solution {
public:
    int sum_(TreeNode* root, int is_left)
    {
        if(nullptr == root) { return 0;}

        if(nullptr == root->left && nullptr == root->right)
        {
            return is_left ? root->val : 0;
        }

        return sum_(root->left, 1) + sum_(root->right, 0);
    }

    int sumOfLeftLeaves(TreeNode* root) {
        return sum_(root, 0);
    }
};
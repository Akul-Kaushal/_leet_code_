/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    TreeNode *findMax(TreeNode* root)
    {
        if(nullptr == root) { return nullptr; }
        else if(nullptr == root->right) { return root; }
        return findMax(root->right);
    }
    TreeNode *findMin(TreeNode* root)
    {
        if(nullptr == root) { return nullptr; }
        else if(nullptr == root->left) { return root; }
        return findMin(root->left);
    }

    bool isValidBST(TreeNode* root) {
        if( nullptr == root) { return true;}
        if ( root->left && findMax(root->left)->val >= root->val) {return false;}
        if ( root->right && findMin(root->right)->val <= root->val) {return false;}

        return (isValidBST(root->left) && isValidBST(root->right));
    }
};
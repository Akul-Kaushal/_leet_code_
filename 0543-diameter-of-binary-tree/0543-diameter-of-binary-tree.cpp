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
    // int height(TreeNode* root)
    // {
    //     if(nullptr ==  root){return 0;}
    //     return 1+max(height(root->left),height(root->right));
    // }
    int maxDiameter = 0;
    int height(TreeNode* root)
    {
        if(nullptr == root) {return 0;}

        int lHeight=height(root->left);
        int rHeight=height(root->right);
        
        maxDiameter = max(maxDiameter, lHeight+rHeight);

        return 1+max(lHeight,rHeight);
    }
    int diameterOfBinaryTree(TreeNode* root) {
        height(root);
        return maxDiameter;
    }


};
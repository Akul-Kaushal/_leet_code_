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
    TreeNode* logic(TreeNode*root, int k , int &count)
    {
        if(nullptr == root) { return nullptr; }
        TreeNode* left=logic(root->left,k,count);
        if(left) { return left;}
        if(++count==k)
        {
            return root;            
        }
        return logic(root->right,k,count);
    }

    int kthSmallest(TreeNode* root, int k) {
        int count=0;
        TreeNode* value = logic(root,k,count);
        return value?value->val:-1;
    }
};
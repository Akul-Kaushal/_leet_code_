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
    void recursion(TreeNode *root, vector<int> &list)
    {
        if (nullptr == root) { return;}
        recursion(root->left, list);
        list.push_back(root->val);
        recursion(root->right, list);
    }


    vector<int> inorderTraversal(TreeNode* root) {
        vector<int> result;
        recursion(root,result);
        return result;
    }
};
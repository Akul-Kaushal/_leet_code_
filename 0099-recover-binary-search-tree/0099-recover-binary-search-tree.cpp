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
    TreeNode* first = nullptr;
    TreeNode* second = nullptr;
    TreeNode* prev= new TreeNode(INT_MIN);

    void swap(int& i,int& j)
    {
        i = i+j;
        j = i-j;
        i = i-j;
        return;
    }

    void logic(TreeNode* root)
    {
        if(nullptr == root) { return ;}

        logic(root->left);

        if(prev && prev->val > root->val)
        {
            if(nullptr == first)
            {
                first = prev;
            }
            second = root;
        }
        prev= root;
        logic(root->right);
    }

    void recoverTree(TreeNode* root) {
        logic(root);

        if(first && second)
        {
            swap(first->val, second->val);
        }
    }
};
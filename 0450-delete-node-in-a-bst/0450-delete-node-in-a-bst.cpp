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
    TreeNode *findmax(TreeNode*root)
    {
        if( nullptr == root) { return nullptr; }
        else if(root->right == nullptr) { return root;}
        else
        {
            return findmax(root->right);
        }
    }

    TreeNode* deleteNode(TreeNode* root, int key) {
        TreeNode * temp;
        if( nullptr == root) { return root;}

        else if(key < root->val) { root->left = deleteNode(root->left, key);}
        else if(key > root->val) { root->right = deleteNode(root->right, key);}
        else
        {
            if( root->left && root->right)
            {
                    temp = findmax(root->left);
                    root->val=  temp->val;
                    root->left = deleteNode(root->left, root->val);
            }
            else
            {
                temp = root;
                if(nullptr == root->left ) { root = root->right;}
                else if(nullptr == root->right) { root = root->left;}
                delete temp;
            }
        }
        return root;
    }
};
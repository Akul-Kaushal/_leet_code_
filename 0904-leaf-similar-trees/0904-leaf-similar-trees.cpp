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
    void store_leaf(TreeNode* root, vector<int> &list)
    {
        if(nullptr == root) { return;}
        if(nullptr == root->left && nullptr == root->right)
        {
            list.push_back(root->val);
            return;
        }
        store_leaf(root->left, list);
        store_leaf(root->right, list);
    };

    bool leafSimilar(TreeNode* root1, TreeNode* root2) {
        vector<int> list1, list2;
        store_leaf(root1, list1);  
        store_leaf(root2, list2);

        return list1==list2;     
    }
};
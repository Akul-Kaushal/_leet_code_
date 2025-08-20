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
    void logic(TreeNode* root, int depth, vector<int> &list)
    {
        if (nullptr == root) { return; }

        if(list.size() == depth)
        {
            list.push_back(root->val);
        }  

        logic(root->right, depth+1, list);
        logic(root->left, depth+1, list);

    }

    vector<int> rightSideView(TreeNode* root) {
        vector<int> list;
        logic(root, 0, list);
        return list;
    }
};
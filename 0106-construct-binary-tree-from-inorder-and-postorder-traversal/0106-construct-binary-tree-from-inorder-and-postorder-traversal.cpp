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
    unordered_map<int, int> inorder_index;
    int postorder_index;

    TreeNode* build(vector<int>& inorder, vector<int>& postorder, int start, int end)
    {
        if (start > end) { return nullptr;}

        int root_val = postorder[postorder_index--];
        TreeNode* root = new TreeNode(root_val);
        int index = inorder_index[root_val];

        root->right = build(inorder, postorder, index+1, end);
        root->left = build(inorder, postorder, start , index-1);

        return root;
    }

    TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
        postorder_index = inorder.size()-1;

        for(int i=0; i<inorder.size(); i++)
        {
            inorder_index[inorder[i]] = i;
        }
        return build(inorder, postorder, 0, inorder.size()-1);
    }
};
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
    void dfs(TreeNode* root, int target, vector<vector<int>> &list, vector<int> path)
    {
        if(nullptr == root) { return; }
        path.push_back(root->val);
        if(nullptr == root->left && nullptr == root->right && target==root->val){
            list.push_back(path);
        }
        dfs(root->left, target-root->val, list, path);
        dfs(root->right, target-root->val, list, path);

    }

    vector<vector<int>> pathSum(TreeNode* root, int targetSum) {
        
        vector<vector<int>> list;
        vector<int> path;

        dfs(root, targetSum, list, path);

        return list;
    }
};
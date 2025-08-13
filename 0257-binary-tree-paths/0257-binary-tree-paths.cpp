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
    void dfs(TreeNode* root, string path, vector<string> &list)
    {
        if(nullptr == root) { return;}

        if(!path.empty()) { path+= "->";}
        path+= to_string(root->val);

        if(nullptr == root->left && nullptr == root->right) {
            list.push_back(path);
            return;
        }else
        {
            dfs(root->left,path,list);
            dfs(root->right,path,list);
        }
    }

    vector<string> binaryTreePaths(TreeNode* root) {
        vector<string> list;
        dfs(root,"", list);

        return list;
    }
};
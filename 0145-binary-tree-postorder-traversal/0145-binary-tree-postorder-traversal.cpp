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
    void logic(TreeNode* root, vector<int> &list)
    {
        stack<TreeNode*> s;
        TreeNode*prev = nullptr;
        do{
            while(root)
            {
                s.push(root);
                root = root->left;
            }
            while(nullptr == root && !s.empty())
            {
                root = s.top();
                if(nullptr == root->right || root->right == prev){
                    list.push_back(root->val);
                    s.pop();
                    prev = root;
                    root = nullptr;
                }
                else
                {
                    root = root->right;
                }
            }
        }while(!s.empty());
    }

    vector<int> postorderTraversal(TreeNode* root) {
        vector<int> list;
        logic(root, list);
        return list;
    }
};
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
    void logic(TreeNode* root, vector<vector<int>> &list)
    {
        if(nullptr == root) { return ;}
        
        
        queue<TreeNode*> q;
        q.push(root);

        
        while(!q.empty())
        {
            int size = q.size();
            vector <int> store;

            for(int i=0; i<size; i++)
            {
                TreeNode* temp = q.front();
                q.pop();

                if(temp->left) { q.push(temp->left);}
                if(temp->right) { q.push(temp->right);}
                store.push_back(temp->val);
            }
            list.push_back(store);
        }
        return ;
    }

    vector<vector<int>> levelOrderBottom(TreeNode* root) {
        vector<vector<int>> list;
        logic(root, list);
        reverse(list.begin(), list.end());
        return list;
    }
};
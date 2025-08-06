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
    void level(TreeNode *root, vector<vector<int>> &list, queue<TreeNode*> q)
    {
        if(nullptr == root){return;}      
        
        q.push(root);

        while(!q.empty())
        {
            int levelSize = q.size();
            vector<int> cur;

            for(int i=0; i<levelSize; i++)
            {
                
                TreeNode *temp; 
                temp = q.front();
                q.pop();
                cur.push_back(temp->val);

                if(temp->left){
                    q.push(temp->left);
                }
                if(temp->right)
                {
                    q.push(temp->right);
                }
            }
            list.push_back(cur);
        }
    }

    vector<vector<int>> levelOrder(TreeNode* root) {
            vector<vector<int>> list;
            queue<TreeNode*> q;
            level(root,list,q);
            return list;
    }
};
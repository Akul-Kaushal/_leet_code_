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
        if ( nullptr == root) {return;}
        queue<TreeNode*> q;
        q.push(root);

        while(!q.empty())
        {
            int max_ = INT_MIN;
            int size = q.size();
            for(int i=0; i<size; i++)
            {
                TreeNode *temp = q.front();
                q.pop();
                max_ = max(max_,temp->val);

                if(temp->left) { q.push(temp->left);}
                if(temp->right) { q.push(temp->right);}
            }
            list.push_back(max_);
        }
        return;
    }

    vector<int> largestValues(TreeNode* root) {
        vector<int> list;
        logic(root,list);
        return list;
    }
};
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
    vector<vector<int>> logic(TreeNode* root, vector<vector<int>> &list)
    {
        if(nullptr == root) { return list;}

        bool button=true;
        queue<TreeNode*> q;
        q.push(root);

        while(!q.empty())
        {
            int size = q.size();
            vector<int> level(size);

            for(int i=0; i< size; i++)
            {
                TreeNode* temp = q.front();
                q.pop();

                int idx = button ? i : (size-i-1);
                level[idx] = temp->val;

                if (temp->left) { q.push(temp->left);}
                if (temp->right) { q.push(temp->right);}
            }

            list.push_back(level);
            button = !button;
        }

        return list;
    }

    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
        vector<vector<int>> list;
        logic(root,list);

        return list;
    }
};
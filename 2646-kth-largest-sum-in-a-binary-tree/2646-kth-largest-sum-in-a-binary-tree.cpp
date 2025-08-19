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
    long long logic(TreeNode* root, int k, vector<long long> &list)
    {
        if(nullptr == root) { return 0;}

        queue<TreeNode*> q;
        q.push(root);

        while(!q.empty())
        {
            int size = q.size();
            long long sum = 0;

            for(int i=0; i<size; i++)
            {
                TreeNode* temp = q.front();
                q.pop();
                sum += temp->val;
                if( temp-> left ) { q.push(temp->left); }
                if ( temp->right ) { q.push(temp->right); }
            }
            list.push_back(sum);
        }
        sort(list.begin(), list.end(), greater<long long> ());
        return (k <= list.size() ? list[k-1] : -1);
    }

    long long kthLargestLevelSum(TreeNode* root, int k) {
        vector<long long> list;
        return logic(root, k, list);
    }
};
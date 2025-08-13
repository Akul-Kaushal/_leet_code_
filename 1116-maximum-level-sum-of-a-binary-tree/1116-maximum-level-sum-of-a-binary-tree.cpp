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
    int maxLevelSum(TreeNode* root) {
        if(nullptr == root) {return 0;}

        TreeNode* temp;
        queue<TreeNode*> q;
        q.push(root);
        q.push(nullptr);

        int cur_sum=0, max_sum=INT_MIN, max_lvl=0, lvl = 1;
        while(!q.empty())
        {
            temp = q.front();
            q.pop();
            if(nullptr == temp){
                if(cur_sum > max_sum)
                {
                    max_sum = cur_sum;
                    max_lvl = lvl;
                }
                cur_sum= 0;
                if(!q.empty()) {q.push(nullptr);}
                lvl++;
            }
            else{
                cur_sum += temp->val;
                if(temp->left){q.push(temp->left);}
                if(temp->right){q.push(temp->right);}
            }
        }
        return max_lvl;
    }
};
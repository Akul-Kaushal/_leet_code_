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
    bool check_l_r(TreeNode* l, TreeNode* r)
    {
        if(nullptr == l && nullptr == r) {return true;}
        if(nullptr == l || nullptr == r) {return false;}

        return ((l->val == r->val) && check_l_r(l->left,r->right) && check_l_r(l->right,r->left));
    };

    bool isSymmetric(TreeNode* root) {
        if(nullptr==root) {return true;}
        return check_l_r(root->left,root->right);
    }
};
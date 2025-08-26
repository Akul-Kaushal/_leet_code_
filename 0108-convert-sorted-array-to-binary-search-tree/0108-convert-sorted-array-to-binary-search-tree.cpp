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
    TreeNode* logic(vector<int> &nums, int left, int right)
    {
        int mid;
        TreeNode * root = nullptr;
        if ( left>right) { return nullptr;}
        if(left == right) {
            root = new TreeNode(nums[left]);
        }
        else
        {
            mid = left + (right-left)/2;
            root = new TreeNode(nums[mid]);
            root->left = logic(nums, left, mid-1);
            root->right = logic(nums, mid+1, right);
        }
        return root;
    }

    TreeNode* sortedArrayToBST(vector<int>& nums) {
     return logic(nums,0, nums.size()-1);  
    }
};
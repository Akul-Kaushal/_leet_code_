/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
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
    int count_node(ListNode* head)
    {
        int count=0;
        while(nullptr != head)
        {
            count ++;
            head = head->next;
        }
        return count;
    }

    TreeNode* sorted_list(ListNode * &head, int left, int right)
    {
        if(left>right) { return nullptr;}

        int mid = left + (right-left)/2;
        TreeNode* leftchild = sorted_list(head,left,mid-1);
        TreeNode* parent = new TreeNode(head->val);
        parent->left = leftchild;
        head = head->next;
        parent->right = sorted_list(head,mid+1,right);
        return parent;
    }

    TreeNode* sortedListToBST(ListNode* head) {
        // cout << count_node(head);
        return sorted_list(head, 0, count_node(head)-1);
    }
};
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    bool hasCycle(ListNode *head) {
        if(nullptr == head || nullptr == head->next) { return false;}

        ListNode* sp, *fp;
        sp = head;
        fp = head->next;

        while(fp && fp->next)
        {
            sp = sp->next;
            fp = fp->next->next;
            if(sp == fp) { return true;}
        }
        return false;
    }
};
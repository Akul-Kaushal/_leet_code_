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
    ListNode *detectCycle(ListNode *head) {
        if(nullptr == head || nullptr == head->next) { return nullptr;}

        ListNode* sp, *fp;
        sp = head;
        fp = head;
        int _check =0;

        while(fp && fp->next){
            sp = sp->next;
            fp = fp->next->next;
            if(sp==fp)
            {
                sp=head;
                while(sp!=fp)
                {
                    sp=sp->next;
                    fp=fp->next;
                }
                return sp;
            }
        }

        return nullptr;
    }
};
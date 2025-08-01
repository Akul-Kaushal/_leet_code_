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

        while(sp != fp){
            if(nullptr == fp || nullptr == fp->next) { return false;}
            sp = sp->next;
            fp = fp->next->next;
            // if(sp==fp)
            // {
            //     // _check = 1;
            //     //break;
            //     return true;
            // }
        }
        // if(_check){
        //     sp=head;
        //     while(sp!=fp)
        //     {
        //         sp=sp->next;
        //         fp=fp->next;
        //     }
        //     return true;
        // }

        return true;
    }
};
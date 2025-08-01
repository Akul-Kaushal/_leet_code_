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
        ListNode* sp, *fp;
        sp = fp = head;
        int _check=0;

        while(fp && fp->next){
            sp = sp->next;
            fp = fp->next->next;
            if(sp==fp)
            {
                // _check = 1;
                //break;
                return true;
            }
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

        return false;
    }
};
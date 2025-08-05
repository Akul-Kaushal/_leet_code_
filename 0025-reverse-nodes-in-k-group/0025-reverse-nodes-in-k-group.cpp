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
class Solution {
public:
    ListNode* get_K_one_node(int k, ListNode*head)
    {   ListNode* kth=head;
        int i=0;
        if(!head){return nullptr;}
        for(i=0; kth && (i<k) ; i++, kth=kth->next);
        return kth;
    };

    int has_Nodes(ListNode *head, int k)
    {   int i=0;
        for(i=0; head&&(i<k); ++i, head=head->next);
        if(i==k) {return 1;}
        return 0;
    };

    ListNode* reverseKGroup(ListNode* head, int k) {
        if(0==k || 1==k) {return head;} 

        ListNode *cur=head;
        ListNode dummy(0);
        ListNode *tail=&dummy;
        
        int i=0;
        
        while(has_Nodes(cur,k))
        {
            ListNode *g_h = cur;
            ListNode *n_g_h = get_K_one_node(k,cur);
            ListNode *temp = n_g_h;

            i=0;
            while(i<k)
            {
                ListNode *next = cur->next;
                cur->next=temp;
                temp=cur;
                cur=next;
                i++;
            }
            tail->next = temp;
            tail = g_h;

        }
        return dummy.next;
    }
};
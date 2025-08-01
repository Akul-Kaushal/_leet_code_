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
     ListNode* removeNthFromEnd(ListNode* head, int n) {
        ListNode extra(0);
        extra.next = head;

        ListNode *ptemp = &extra;
        ListNode *ktemp = &extra;
        for( int i=0; i<=n ; i++)
        {
            ptemp = ptemp->next;
        }

        while(ptemp)
        {
            ptemp = ptemp->next;
            ktemp = ktemp->next;
        }

        ListNode* temp = ktemp->next;
        ktemp->next=temp->next;

        return extra.next;
    }
};
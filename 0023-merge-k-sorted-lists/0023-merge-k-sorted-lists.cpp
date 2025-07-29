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
    ListNode* mergeTwoLists(ListNode* list1, ListNode* list2)
    {
        if(nullptr == list1) { return list2;}
        if(nullptr == list2) {return list1;}

        if(list1->val <= list2->val) {
            list1->next = mergeTwoLists(list1->next,list2);
            return list1;
        }
        else
        {
            list2->next = mergeTwoLists(list1,list2->next);
            return list2;
        }
    }

    ListNode* mergeKLists(vector<ListNode*>& lists) {
        if (lists.empty()) {return nullptr;}

        int count = 1;
        while(count < lists.size())
        {
            for(int i=0; i+count<lists.size(); i+= count*2)
            {
                lists[i] = mergeTwoLists(lists[i], lists[i+count]);
            }
            count = count *2;
        }

        return lists[0];
    }
};
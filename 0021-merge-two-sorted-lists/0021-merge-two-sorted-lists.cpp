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
    ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {
        ListNode* dummy=new ListNode(0);
        ListNode* new_list=dummy;

        ListNode* p=list1;
        ListNode* q=list2;

        while(p && q)
        {
            if(p->val>=q->val)
            {
                new_list->next=q;
                new_list=q;
                q=q->next;
            }
            else if(q->val>=p->val)
            {
                new_list->next=p;
                new_list=p;
                p=p->next;
            }
        }

        while(p)
        {
            new_list->next=p;
            new_list=p;
            p=p->next;
        }

         while(q)
        {
            new_list->next=q;
            new_list=q;
            q=q->next;
        }

        return dummy->next;
    }
};
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
    ListNode* removeElements(ListNode* head, int val) {
        if(head==NULL)
        {
            return NULL;
        }

        ListNode* p=new ListNode(0);
        ListNode* q=head;

        while(q)
        {
            if(q->val==val && q==head)
            {
                q=q->next;
                head=q;
                continue;
            }
            if(q->val==val && q->next==NULL)
           {
            p->next=NULL;
           }
           if(q->val!=val)
           {
            p->next=q;
            p=q;
           }
            q=q->next;
           
        }

        if(p->val==0)
        {
            return NULL;
        }
        return head;
    }
};
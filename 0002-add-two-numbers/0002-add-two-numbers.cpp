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
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        ListNode* p=l1;
        ListNode* q=l2;

        ListNode* dummy=new ListNode(0);
        ListNode* r=dummy;

        int carr=0;

        while(p && q)
        {
            int sum=p->val+q->val+carr;
            r->next=new ListNode(sum%10);
            r=r->next;

            if(sum>9)
            {
                carr=sum/10;
            }
            else
            {
                carr=0;
            }
            p=p->next;
            q=q->next;
        }

        while(p)
        {
            int sum=p->val+carr;

            r->next=new ListNode(sum%10);
            r=r->next;

            if(sum>9)
            {
                carr=sum/10;
            }
            else
            {
                carr=0;
            }
            p=p->next;

        }

         while(q)
        {
            int sum=q->val+carr;

            r->next=new ListNode(sum%10);
            r=r->next;

            if(sum>9)
            {
                carr=sum/10;
            }
            else
            {
                carr=0;
            }
            q=q->next;

        }
        if(carr)
        {
            r->next=new ListNode(1);
            r=r->next;
        }
        r->next=NULL;
        return dummy->next;
    }
};
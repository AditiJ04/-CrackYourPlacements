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
    ListNode* rev(ListNode* head)
    {
        ListNode* p=head;
        ListNode* q=NULL;
        ListNode* r=NULL;

        while(p)
        {
            r=q;
            q=p;
            p=p->next;
            q->next=r;
        }
        return q;
    }
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        ListNode* a=rev(l1);
        ListNode* b=rev(l2);

        ListNode* dummy=new ListNode(0);
        ListNode* c=dummy;

        int carr=0;

        while(a && b)
        {
            int sum=a->val+b->val+carr;

            c->next=new ListNode(sum%10);
            c=c->next;

            if(sum>9)
            {
                carr=sum/10;
            }
            else
            {
                carr=0;
            }
            a=a->next;
            b=b->next;
        }

        while(a)
        {
            int sum=a->val+carr;
            c->next=new ListNode(sum%10);
            c=c->next;

            if(sum>9)
            {
                carr=sum/10;
            }
            else
            {
                carr=0;
            }
            a=a->next;
        }

          while(b)
        {
            int sum=b->val+carr;
            c->next=new ListNode(sum%10);
            c=c->next;

            if(sum>9)
            {
                carr=sum/10;
            }
            else
            {
                carr=0;
            }
            b=b->next;
        }

        if(carr)
        {
            c->next=new ListNode(carr%10);
            c=c->next;
        }
        return rev(dummy->next);
    }
};
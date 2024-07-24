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
        ListNode* r=NULL;
        ListNode* q=NULL;

        while(p)
        {
            r=q;
            q=p;
            p=p->next;
            q->next=r;
        }
        return q;
    }
    bool isPalindrome(ListNode* head) {
        
        ListNode* f=head;
        ListNode* s=head;

        while(f->next!=NULL && f->next->next!=NULL)
        {
            f=f->next->next;
            s=s->next;
        }

        s->next=rev(s->next);
        s=s->next;
        ListNode* p=head;

        while(s)
        {
            if(p->val!=s->val)
            {
                return false;
            }
            p=p->next;
            s=s->next;
        }

        return true;
    }
};
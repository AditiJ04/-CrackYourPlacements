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
    void reorderList(ListNode* head) {
      ListNode* s=head;
      ListNode* f=head;

      while(f && f->next && f->next->next)
      {
        s=s->next;
        f=f->next->next;
      }

      ListNode* head1=rev(s->next);

      s->next=NULL;

      ListNode* p=head;
      ListNode* q=head1;

      while(q)
      {
        ListNode* tmp1=p->next;
        ListNode* tmp2=q->next;

        p->next=q;
        
        q->next=tmp1;

        p=tmp1;
        q=tmp2;
      }
    
    }
};
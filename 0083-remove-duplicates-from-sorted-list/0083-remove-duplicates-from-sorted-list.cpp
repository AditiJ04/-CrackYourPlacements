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
    ListNode* deleteDuplicates(ListNode* head) {
        ListNode* p=head;
    

        if(head==NULL)
        {
            return NULL;
        }
          ListNode* q=p->next;
        while(q)
        {
        
            if(p->val==q->val && q->next==NULL)
            {
                p->next=NULL;
            }
            if(p->val==q->val)
            {
                q=q->next; 
            }
           else if(p->val!=q->val)
           {
            p->next=q;
            p=q;
            q=q->next;
           }
           
        }

        return head;
    }
};
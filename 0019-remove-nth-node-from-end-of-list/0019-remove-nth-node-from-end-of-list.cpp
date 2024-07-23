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
    
    int Count(ListNode* head)
    {
        int cnt=1;

        ListNode* p=head;

        while(p->next)
        {
            p=p->next;
            cnt++;
        }
        return cnt;
    }
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        int k=Count(head);

        int j=k-n;

        ListNode* q=head;
        if(j==0)
        {
        ListNode* newHead = head->next;
        delete head;
        return newHead;
        }

        int i=1;

        while(i<j)
        {
            q=q->next;
            i++;
        }

        if(q->next->next==NULL)
        {
            delete q->next;
            q->next=NULL;
        }
        else
        {
        ListNode* r=q->next;
        q->next=q->next->next;
        delete r;
        }
        return head;
    }
};
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
    int Countnodes(ListNode* head)
    {
        ListNode* p=head;
        int cnt=0;

        while(p)
        {
            cnt++;
            p=p->next;
        }
        return cnt;
    }
    ListNode* middleNode(ListNode* head) {
        int c=Countnodes(head);

        int k=c/2;

        int i=1;

        ListNode* q=head;

        while(i<=k)
        {
            q=q->next;
            i++;
        }

        return q;
    }
};
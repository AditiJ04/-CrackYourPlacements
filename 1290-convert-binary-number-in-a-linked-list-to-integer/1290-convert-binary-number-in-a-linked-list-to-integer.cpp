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
        int cnt=0;
        ListNode* p=head;
        while(p)
        {
            cnt++;
            p=p->next;
        }

        return cnt;
    }
    int getDecimalValue(ListNode* head) {
        int k=Count(head);

        ListNode* q=head;
        int sum=0;

        while(q)
        {
            sum+=q->val*pow(2,k-1);
            k--;
            q=q->next;
        }

        return sum;
    }
};
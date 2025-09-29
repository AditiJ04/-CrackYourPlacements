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
    ListNode* swapPairs(ListNode* head) {
        ListNode* p=head;

        while(p!=NULL && p->next!=NULL)
        {
            ListNode* q=p->next;
            swap(p->val,q->val);

            p=p->next->next;
        }

        return head;
    }
};
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
        ListNode* dummy=new ListNode();
        dummy->next=head;
        swap(dummy);

        return dummy->next;
    }

    void swap(ListNode* node)
    {
        if(node==NULL)
        {
            return;
        }
        ListNode* f=node->next;
        ListNode* second=NULL;

        if(f!=NULL)
        {
            second=f->next;
        }
        if(second!=NULL)
        {
            ListNode* snext=second->next;
            second->next=f;
            node->next=second;
            f->next=snext;
            swap(f);
        }
    }
};
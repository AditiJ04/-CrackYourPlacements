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
    ListNode* oddEvenList(ListNode* head) {
        ListNode* p=head;
        ListNode* q=head;

        vector<int>odd;
        vector<int>even;

        int cnt=1;

        while(p)
        {
            if(cnt%2==0)
            {
                even.push_back(p->val);
            }
            else
            {
                odd.push_back(p->val);
            }
            cnt++;
            p=p->next;
        }

        int i=0;
        while(i<odd.size())
        {
            q->val=odd[i];
            i++;
            q=q->next;
        }

   //     q->val=even[0];

        int j=0;
        while(j<even.size())
        {
            q->val=even[j];
            j++;
            q=q->next;
        }
        return head;
    }
};
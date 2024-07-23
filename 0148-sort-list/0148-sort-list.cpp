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
    ListNode* sortList(ListNode* head) {
        vector<int>ans;

        ListNode* p=head;

        while(p)
        {
            ans.push_back(p->val);
            p=p->next;        
        }

        sort(ans.begin(),ans.end());

        ListNode* q=head;

        int i=0;

        while(i<ans.size())
        {
            q->val=ans[i];
            q=q->next;
            i++;
        }
        return head;
    }
};
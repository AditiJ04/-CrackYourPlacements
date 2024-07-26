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
    ListNode* partition(ListNode* head, int x) {
        vector<int>ans;
        vector<int>v;

        vector<int>res;
        ListNode* p=head;

        while(p)
        {
            if(p->val<x)
            {
                ans.push_back(p->val);
            }
            else
            {
                v.push_back(p->val);
            }
            p=p->next;
        }

        res.insert(res.end(),ans.begin(),ans.end());
        res.insert(res.end(),v.begin(),v.end());

        ListNode* q=head;
        int i=0;

        while(q)
        {
            q->val=res[i];
            q=q->next;
            i++;
        }

        return head;
    }
};
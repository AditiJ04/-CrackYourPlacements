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
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        vector<int>ans;

        for (int i = 0; i < lists.size(); i++) {
        ListNode* current = lists[i];
        while (current != nullptr) {
            ans.push_back(current->val);
            current = current->next;
        }
    }

        if(ans.empty())
        {
            return NULL;
        }
        sort(ans.begin(),ans.end());

        ListNode* nhead=new ListNode(ans[0]);
        ListNode* p=nhead;

        for(int i=1;i<ans.size();i++)
        {
            p->next=new ListNode(ans[i]);
            p=p->next;
        }
        p->next=NULL;

        return nhead;
    }
};
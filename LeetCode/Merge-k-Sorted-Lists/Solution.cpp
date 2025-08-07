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

        if(lists.empty()) return NULL;
        vector<int>ans;

        for(auto list:lists)
        {
            if(list==NULL) continue;
            while(list!=NULL)
            {
                ans.push_back(list->val);
                list=list->next;
            }
        }

        if(ans.empty()) return NULL;
        sort(ans.begin(),ans.end());
        ListNode* head=new ListNode(ans[0]);
        ListNode* phead=head;

        for(int i=1;i<ans.size();i++)
        {
            phead->next=new ListNode(ans[i]);
            phead=phead->next;
        }
        phead->next=NULL;
        return head;
    }
};
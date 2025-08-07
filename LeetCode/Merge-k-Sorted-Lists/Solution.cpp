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
        priority_queue<pair<int,ListNode*>,vector<pair<int,ListNode*>>,
        greater<pair<int,ListNode*>>>pq;

        int n=lists.size();

        for(int i=0;i<n;i++)
        {
            if(lists[i])
            {
            pq.push({lists[i]->val,lists[i]});
            }
        }

        if(pq.empty()) return NULL;
        ListNode* dummy=new ListNode(0);
        ListNode* tail=dummy;
        while(!pq.empty())
        {
            auto top=pq.top();
            tail->next=top.second;
            tail=tail->next;
            pq.pop();

            if(top.second->next)
            {
                pq.push({top.second->next->val,top.second->next});
            }
        }

        return dummy->next;
    }
};
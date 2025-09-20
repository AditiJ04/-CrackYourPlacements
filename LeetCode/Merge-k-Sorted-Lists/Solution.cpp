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

    priority_queue<pair<int,ListNode*>,vector<pair<int,ListNode*>>,greater<pair<int,ListNode*>>>pq;


    ListNode* mergeKLists(vector<ListNode*>& lists) {

        int n=lists.size();
        for(int i=0;i<n;i++)
        {
            if(lists[i]) {pq.push({lists[i]->val,lists[i]});}
        }

        if(pq.empty()) return NULL;
        ListNode* curr=NULL,*prev=NULL;
        while(!pq.empty())
        {
            ListNode* node=pq.top().second;

            if(curr==NULL) curr=node;
            if(prev==NULL) prev=curr;
            else
            {
            prev->next=node;
            prev=prev->next;
            }

            if(node->next) pq.push({node->next->val,node->next});
            pq.pop();
        }
      //  prev->next=NULL;

        return curr;
    }
};
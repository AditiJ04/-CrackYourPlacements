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
    ListNode* reverseBetween(ListNode* head, int left, int right) {
        vector<int>ans;

        stack<int>st;

        int cnt=1;

        ListNode* p=head;

        while(cnt<=right)
        {
            if(cnt>=left && cnt<=right)
            {
                st.push(p->val);
            }
            else{
            ans.push_back(p->val);
            }
            p=p->next;
            cnt++;
        }

        while(!st.empty())
        {
            ans.push_back(st.top());
            st.pop();
        }

        while(p)
        {
            ans.push_back(p->val);
            p=p->next;
        }

        ListNode* q=head;

        int i=0;
        while(q)
        {
            q->val=ans[i];
            i++;
            q=q->next;
        }

        return head;
    }
};
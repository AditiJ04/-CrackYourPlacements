1/**
2 * Definition for singly-linked list.
3 * struct ListNode {
4 *     int val;
5 *     ListNode *next;
6 *     ListNode(int x) : val(x), next(NULL) {}
7 * };
8 */
9class Solution {
10public:
11    bool hasCycle(ListNode *head) {
12        ListNode* p=head;
13        ListNode* q=head;
14
15        while(q!=NULL && q->next!=NULL)
16        {
17            p=p->next;
18            q=q->next->next;
19
20            if(p==q) return true;
21        }
22
23        return false;
24    }
25};
1/**
2 * Definition for singly-linked list.
3 * struct ListNode {
4 *     int val;
5 *     ListNode *next;
6 *     ListNode() : val(0), next(nullptr) {}
7 *     ListNode(int x) : val(x), next(nullptr) {}
8 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
9 * };
10 */
11class Solution {
12public:
13    ListNode* reverseList(ListNode* head) {
14        ListNode* p=head;
15        ListNode* q=NULL;
16        ListNode* r=NULL;
17
18        while(p!=NULL)
19        {
20            q=p;
21            p=p->next;
22            q->next=r;
23            r=q;
24        }
25
26        return q;
27    }
28};
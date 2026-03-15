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
15
16        ListNode* q=NULL;
17        ListNode* r=NULL;
18
19        while(p!=NULL)
20        {
21            q=p;
22            p=p->next;
23            q->next=r;
24            r=q;
25        }
26
27        return q;
28    }
29};
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
14        if(head==NULL || head->next==NULL) return head;
15
16        ListNode* p=head;
17        ListNode* q=NULL;
18        ListNode* r=p->next;
19
20        while(r!=NULL)
21        {
22            p->next=q;
23            q=p;
24            p=r;
25            r=r->next;
26        }
27
28        p->next=q;
29        return p;
30    }
31};
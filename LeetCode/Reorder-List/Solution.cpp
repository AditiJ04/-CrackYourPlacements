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
13    ListNode* revList(ListNode* head)
14    {
15        ListNode* p=head;
16        ListNode* q=NULL;
17        ListNode* r=NULL;
18
19        while(p)
20        {
21            r=q;
22            q=p;
23            p=p->next;
24            q->next=r;
25        }
26
27        return q;
28    }
29    void reorderList(ListNode* head) {
30        ListNode* s=head;
31        ListNode* f=head;
32
33        while(f && f->next && f->next->next)
34        {
35            s=s->next;
36            f=f->next->next;
37        }
38
39        ListNode* nh=revList(s->next);
40        s->next=NULL;
41        ListNode* p=head;
42        ListNode* q=nh;
43
44        while(q)
45        {
46            ListNode* t1=p->next;
47            ListNode* t2=q->next;
48
49            p->next=q;
50            q->next=t1;
51
52            p=t1;
53            q=t2;
54        }
55
56
57    }
58};
59
60// 1->2->4->3
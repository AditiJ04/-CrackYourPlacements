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
13    ListNode* rev(ListNode* head)
14    {
15        ListNode* p=head;
16        ListNode* q=NULL;
17        ListNode* r=NULL;
18        while(p)
19        {
20            r=q;
21            q=p;
22            p=p->next;
23            q->next=r;
24        }
25
26        return q;
27    }
28    void reorderList(ListNode* head) {
29      ListNode* s=head;
30      ListNode* f=head;
31
32      while(f && f->next && f->next->next)
33      {
34        s=s->next;
35        f=f->next->next;
36      }
37
38      ListNode* head1=rev(s->next);
39
40      s->next=NULL;
41
42      ListNode* p=head;
43      ListNode* q=head1;
44
45      while(q)
46      {
47        ListNode* tmp1=p->next;
48        ListNode* tmp2=q->next;
49
50        p->next=q;
51        
52        q->next=tmp1;
53
54        p=tmp1;
55        q=tmp2;
56      }
57    
58    }
59};
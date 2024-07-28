/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* prev;
    Node* next;
    Node* child;
};
*/

class Solution {
public:
    Node* flatten(Node* head) {
        for(Node* m=head;m;m=m->next)
        {
            if(m->child)
            {
                Node* k=m->next;

                m->next=m->child;
                m->next->prev=m;
                m->child=NULL;

                Node* p=m->next;

                while(p->next)
                {
                    p=p->next;
                }
                p->next=k;

                if(k)
                {
                    k->prev=p;
                }
            }
        }

        return head;
    }
};
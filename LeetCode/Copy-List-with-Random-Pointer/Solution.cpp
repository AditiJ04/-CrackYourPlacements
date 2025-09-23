/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* next;
    Node* random;
    
    Node(int _val) {
        val = _val;
        next = NULL;
        random = NULL;
    }
};
*/

class Solution {
public:
    Node* copyRandomList(Node* head) {
        if(head==NULL)
        {
            return NULL;
        }

        Node* curr=head;
        while(curr!=NULL)
        {
            Node* nnext=curr->next;
            curr->next=new Node(curr->val);
            curr->next->next=nnext;
            curr=nnext;
        }

        curr=head;

        while(curr && curr->next)
        {
            if(curr->random==NULL)
            {
                curr->next->random=NULL;
            }
            else
            {
                curr->next->random=curr->random->next;
            }
            curr=curr->next->next;
        }

        Node* nhead=head->next;
        Node* ncurr=nhead;
        curr=head;

        while(curr  && ncurr)
        {
            curr->next=curr->next?curr->next->next:NULL;
            ncurr->next=ncurr->next?ncurr->next->next:NULL;

            curr=curr->next;
            ncurr=ncurr->next;
        }

        return nhead;

    }
};
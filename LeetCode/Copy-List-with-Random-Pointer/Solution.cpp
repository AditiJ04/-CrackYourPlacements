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
        Node* tmp=head;

        while(tmp!=NULL)
        {
            Node* copy=new Node(tmp->val);
            copy->next=tmp->next;
            tmp->next=copy;
            tmp=tmp->next->next;
        }

        tmp=head;

        while(tmp)
        {
            Node* copy=tmp->next;
            if(tmp->random)
            {
            copy->random=tmp->random->next;
            }
            else
            {
                copy->random=NULL;
            }

            tmp=tmp->next->next;
        }

        Node* dummy=new Node(-1);
        Node* res=dummy;
        tmp=head;


        while(tmp!=NULL)
        {
            res->next=tmp->next;
            tmp->next=tmp->next->next;

            res=res->next;
            tmp=tmp->next;
        }

        return dummy->next;
    }
};
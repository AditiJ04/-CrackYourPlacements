/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* left;
    Node* right;
    Node* next;

    Node() : val(0), left(NULL), right(NULL), next(NULL) {}

    Node(int _val) : val(_val), left(NULL), right(NULL), next(NULL) {}

    Node(int _val, Node* _left, Node* _right, Node* _next)
        : val(_val), left(_left), right(_right), next(_next) {}
};
*/

class Solution {
public:
    Node* connect(Node* root) {

        if(root==NULL) return NULL;
        queue<Node*>que;

        que.push(root);
       

        while(!que.empty())
        {
            int sz=que.size();
            Node* prev=NULL;
            while(sz--)
            {
                Node* curr=que.front();
                
                if(prev) prev->next=curr;
                prev=curr;

                if(curr->left) que.push(curr->left);
                if(curr->right) que.push(curr->right);

                que.pop();
            }
            prev->next=NULL;
        }
        return root;
    }
};
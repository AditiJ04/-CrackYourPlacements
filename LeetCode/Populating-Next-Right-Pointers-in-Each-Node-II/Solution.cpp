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

        if(root==NULL) return root;
        queue<Node*>que;

        que.push(root);
        while(!que.empty())
        {
            int sz=que.size();
            Node* prev=NULL;
            while(sz--)
            {
                Node* fro=que.front();
                que.pop();

                if(prev==NULL)
                {
                    prev=fro;
                }
                else
                {
                    prev->next=fro;
                    prev=prev->next;
                }

                if(fro->left)
                {
                    que.push(fro->left);
                }
                if(fro->right)
                {
                    que.push(fro->right);
                }
            }
            prev->next=NULL;
        }
        return root;
    }
};
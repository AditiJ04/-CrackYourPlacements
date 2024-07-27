//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

struct Node {
    int data;
    Node *next;

    Node(int x) {
        data = x;
        next = NULL;
    }
};

void print(Node *root) {
    Node *temp = root;
    while (temp != NULL) {
        cout << temp->data << " ";
        temp = temp->next;
    }
}


// } Driver Code Ends
/*

The structure of linked list is the following
struct Node
{
    int data;
    Node* next;

    Node(int x){
        data = x;
        next = NULL;
    }

};
*/

class Solution {
  public:
    Node* zigZag(Node* head) {
        // your code goes here
        if(head==NULL || head->next==NULL)
        {
            return head;
        }
        
        Node* p=head;
        bool flg=true;
        
        while(p->next!=NULL)
        {
            if(flg)
            {
                if(p->data>p->next->data)
                {
                    int t=p->data;
                    p->data=p->next->data;
                    p->next->data=t;
                }
                flg=!flg;
            }
            
            else
            {
                if(p->data<p->next->data)
                {
                    int t=p->data;
                    p->data=p->next->data;
                    p->next->data=t;
                }
                flg=!flg;
            }
            
            p=p->next;
        }
        
        return head;
    }
};

//{ Driver Code Starts.

int main() {
    int t, k;
    cin >> t;
    cin.ignore(); // Ignore the newline character after t

    while (t--) {
        string input;
        getline(cin, input); // Read the entire line for the array elements

        stringstream ss(input);
        Node *head = nullptr, *tail = nullptr;
        int x;

        if (ss >> x) {
            head = new Node(x);
            tail = head;
        }

        while (ss >> x) {
            tail->next = new Node(x);
            tail = tail->next;
        }

        Solution ob;
        Node *ans = ob.zigZag(head);
        print(ans);
        cout << endl;
    }
    return 0;
}

// } Driver Code Ends
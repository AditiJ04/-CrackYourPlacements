//{ Driver Code Starts
#include <bits/stdc++.h>
#include <iostream>
#include <set>
#include <sstream>
#include <string>
#include <vector>
using namespace std;

struct Node {
    int data;
    struct Node* next;

    Node(int x) {
        data = x;
        next = NULL;
    }
};

struct Node* buildList() {
    vector<int> arr;
    string input;
    getline(cin, input);
    stringstream ss(input);
    int number;
    while (ss >> number) {
        arr.push_back(number);
    }

    int data = arr[0];
    Node* head = new Node(data);
    Node* tail = head;
    for (int i = 1; i < arr.size(); ++i) {
        data = arr[i];
        tail->next = new Node(data);
        tail = tail->next;
    }
    return head;
}

void printList(Node* n) {
    while (n) {
        cout << n->data << " ";
        n = n->next;
    }
    cout << endl;
}


// } Driver Code Ends
/*
// structure of the node is as follows

struct Node
{
    int data;
    struct Node* next;

    Node(int x){
        data = x;
        next = NULL;
    }

};

*/
class Solution {
  public:
    struct Node* mergeList(struct Node* list1,struct Node* list2)
    {
        struct Node* newnode=new Node(-1);
        struct Node* curr=newnode;
        
        while(list1!=NULL && list2!=NULL)
        {
            int val;
            
            if(list1->data<list2->data)
            {
                val=list1->data;
                list1=list1->next;
            }
            else if(list1->data>list2->data)
            {
                val=list2->data;
                list2=list2->next;
            }
            else
            {
                val=list1->data;
                list1=list1->next;
                list2=list2->next;
            }
            
            Node* node=new Node(val);
            curr->next=node;
            curr=node;
            
            
            while(list1!=NULL && list1->data==val)
            {
                list1=list1->next;
            }
            
             while(list2!=NULL && list2->data==val)
            {
                list2=list2->next;
            }
        }
        
        while(list1!=NULL)
        {
            if(curr!=NULL || curr->data!=list1->data)
            {
                Node* node=new Node(list1->data);
                curr->next=node;
                curr=node;
            }
            list1=list1->next;
        }
        
         while(list2!=NULL)
        {
            if(curr!=NULL || curr->data!=list2->data)
            {
                Node* node=new Node(list2->data);
                curr->next=node;
                curr=node;
            }
            list2=list2->next;
        }
        
        return newnode->next;
    }
    struct Node* findmid(struct Node* head)
    {
        struct Node* slow=head;
        struct Node* fast=head->next;
        
        while(fast!=NULL && fast->next!=NULL)
        {
            slow=slow->next;
            fast=fast->next->next;
        }
        return slow;
    }
    struct Node* mergeSort(struct Node* head)
    {
        if(head==NULL || head->next==NULL)
        {
            return head;
        }
        
        struct Node* mid=findmid(head);
        struct Node* left=head;
        struct Node* right=mid->next;
        
        mid->next=NULL;
        
        left=mergeSort(left);
        right=mergeSort(right);
        
        return mergeList(left,right);
        
    }
    struct Node* makeUnion(struct Node* head1, struct Node* head2) {
        // code here
        
        head1=mergeSort(head1);
        head2=mergeSort(head2);
        
        return mergeList(head1,head2);
    }
};


//{ Driver Code Starts.

int main() {

    int t;
    cin >> t;
    cin.ignore();
    while (t--) {

        Node* first = buildList();

        Node* second = buildList();
        Solution obj;
        Node* head = obj.makeUnion(first, second);
        printList(head);
    }
    return 0;
}

// } Driver Code Ends
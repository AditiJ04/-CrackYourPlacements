//{ Driver Code Starts
// Initial Template for C++
#include <bits/stdc++.h>
using namespace std;

struct Node {
    int data;
    struct Node *next;

    Node(int x) {
        data = x;
        next = NULL;
    }
};

void printList(Node *node) {
    while (node != NULL) {
        cout << node->data << " ";
        node = node->next;
    }
    cout << "\n";
}


// } Driver Code Ends
/*
The structure of linked list is the following

struct Node {
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
    // Function to sort the given linked list using Merge Sort.
    void MergeArr(vector<int>&ans,int s,int e)
    {
        int mid=(s+e)/2;
        int len1=mid-s+1;
        int len2=e-mid;
        
        int* first=new int[len1];
        int* second=new int[len2];
        
        int k=s;
        
        for(int i=0;i<len1;i++)
        {
            first[i]=ans[k++];
        }
        
        k=mid+1;
        
        for(int i=0;i<len2;i++)
        {
            second[i]=ans[k++];
        }
        
        int idx1=0,idx2=0;
        
        int idx=s;
        
        while(idx1<len1 && idx2<len2)
        {
            if(first[idx1]<second[idx2])
            {
                ans[idx++]=first[idx1++];
            }
            else
            {
                ans[idx++]=second[idx2++];
            }
        }
        
        while(idx1<len1)
        {
            ans[idx++]=first[idx1++];
        }
        
        while(idx2<len2)
        {
            ans[idx++]=second[idx2++];
        }
    }
    void Merge(vector<int>&ans,int s,int e)
    {
        if(s>=e)
        {
            return;
        }
        
        int mid=(s+e)/2;
        
        Merge(ans,s,mid);
        Merge(ans,mid+1,e);
        
        MergeArr(ans,s,e);
    }
    Node* mergeSort(Node* head) {
        // your code here
        
        vector<int>ans;
        
        Node* p=head;
        
        while(p!=NULL)
        {
            ans.push_back(p->data);
            p=p->next;
        }
        
        int s=0;
        int e=ans.size()-1;
        
        Merge(ans,s,e);
        
        Node* dummy=new Node(0);
        Node* q=dummy;
        for(int i=0;i<ans.size();i++)
        {
            q->next=new Node(ans[i]);
            q=q->next;
        }
        q->next=NULL;
        
        return dummy->next;
    }
};


//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    cin.ignore();

    while (t--) {
        vector<int> arr;
        string input;
        getline(cin, input);
        stringstream ss(input);
        int number;

        // Read numbers from the input line
        while (ss >> number) {
            arr.push_back(number);
        }
        Node *head = nullptr;
        // Check if the array is empty
        if (!arr.empty()) {
            head = new Node(arr[0]);
            Node *tail = head;
            for (size_t i = 1; i < arr.size(); ++i) {
                tail->next = new Node(arr[i]);
                tail = tail->next;
            }
        }
        Solution obj;
        Node *ans = obj.mergeSort(head);
        printList(ans);
    }
    return 0;
}
// } Driver Code Ends
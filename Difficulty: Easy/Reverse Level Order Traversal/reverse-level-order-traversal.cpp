//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

struct Node
{
    int data;
    struct Node *left;
    struct Node *right;
};
// Utility function to create a new Tree Node
Node* newNode(int val)
{
    Node* temp = new Node;
    temp->data = val;
    temp->left = NULL;
    temp->right = NULL;
    
    return temp;
}
// Function to Build Tree
Node* buildTree(string str)
{   
    // Corner Case
    if(str.length() == 0 || str[0] == 'N')
            return NULL;
    
    // Creating vector of strings from input 
    // string after spliting by space
    vector<string> ip;
    
    istringstream iss(str);
    for(string str; iss >> str; )
        ip.push_back(str);
        
    // Create the root of the tree
    Node* root = newNode(stoi(ip[0]));
        
    // Push the root to the queue
    queue<Node*> queue;
    queue.push(root);
        
    // Starting from the second element
    int i = 1;
    while(!queue.empty() && i < ip.size()) {
            
        // Get and remove the front of the queue
        Node* currNode = queue.front();
        queue.pop();
            
        // Get the current node's value from the string
        string currVal = ip[i];
            
        // If the left child is not null
        if(currVal != "N") {
                
            // Create the left child for the current node
            currNode->left = newNode(stoi(currVal));
                
            // Push it to the queue
            queue.push(currNode->left);
        }
            
        // For the right child
        i++;
        if(i >= ip.size())
            break;
        currVal = ip[i];
            
        // If the right child is not null
        if(currVal != "N") {
                
            // Create the right child for the current node
            currNode->right = newNode(stoi(currVal));
                
            // Push it to the queue
            queue.push(currNode->right);
        }
        i++;
    }
    
    return root;
}

vector<int> reverseLevelOrder(Node* root);

int main()
{

    int t;
    scanf("%d ",&t);
    while(t--)
    {
        string s;
        getline(cin,s);
        Node* root = buildTree(s);
        vector<int> result = reverseLevelOrder(root);
        for (int i = 0; i < result.size(); ++i)
        {
            cout<<result[i]<<" ";
        }
        cout<<endl;
    }
    return 1;
}
// } Driver Code Ends


/*   
struct Node
{
    int data;
    Node* left;
    Node* right;
}; */
vector<int> reverseLevelOrder(Node *root)
{
    // code here
    vector<int>ans;
    
    queue<pair<Node*,int>>que;
    map<int,vector<int>>mp;
    
    que.push(make_pair(root,0));
    
    while(!que.empty())
    {
        /*pair<Node*,int>p=que.front();
        Node* fro=p.first;
        int lev=p.second;*/
        
        int n=que.size();
        
       /* mp[lev].push_back(fro->data);
        que.pop();*/
        
        while(n--)
        {
        pair<Node*,int>p=que.front();
         Node* fro=p.first;
        int lev=p.second;
        que.pop();
     //   int n=que.size();
        
        mp[lev].push_back(fro->data);
        if(fro->left)
        {
            que.push(make_pair(fro->left,-1*(abs(lev)+1)));
        }
        
         if(fro->right)
        {
            que.push(make_pair(fro->right,-1*(abs(lev)+1)));
        }
        
        }
    }
    
    for(auto it:mp)
    {
        for(auto num:it.second)
        {
            ans.push_back(num);
        }
    }
    
    return ans;
}
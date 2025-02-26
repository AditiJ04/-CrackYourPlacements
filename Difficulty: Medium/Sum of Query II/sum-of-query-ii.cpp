//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends

// User function Template for C++

class Solution{
public:
    int query(int s,int e,vector<int>&Tree,int curr,int l,int r)
    {
        if(l>e || r<s)
        {
            return 0;
        }
        
        if(l>=s && r<=e)
        {
            return Tree[curr];
        }
        int mid=l+(r-l)/2;
        return query(s,e,Tree,2*curr+1,l,mid)+query(s,e,Tree,2*curr+2,mid+1,r);
    }
    void buildTree(int i,int l,int r,vector<int>&tree,int arr[])
    {
        if(l==r)
        {
            tree[i]=arr[l];
            return;
        }
        
        int mid=l+(r-l)/2;
        
        buildTree(2*i+1,l,mid,tree,arr);
        buildTree(2*i+2,mid+1,r,tree,arr);
        tree[i]=tree[2*i+1]+tree[2*i+2];
    }
    vector<int> querySum(int n, int arr[], int q, int queries[])
    {
        // code here
        vector<int>Tree(4*n);
        
        buildTree(0,0,n-1,Tree,arr);
        
        vector<int>res;
        
        for(int i=0;i<2*q;i+=2)
        {
            int s=queries[i]-1;
            int e=queries[i+1]-1;
            
            res.push_back(query(s,e,Tree,0,0,n-1));
        }
        return res;
    }
};


//{ Driver Code Starts.

int main(){
    int t;
    cin>>t;
    while(t--){
        int n, q;
        cin>>n;
        int arr[n];
        for(int i = 0;i < n;i++)
            cin>>arr[i];
        cin>>q;
        int queries[2*q];
        for(int i = 0;i < 2*q;i += 2)
            cin>>queries[i]>>queries[i+1];
        
        Solution ob;
        vector<int> ans = ob.querySum(n, arr, q, queries);
        for(int u: ans)
            cout<<u<<" ";
        cout<<endl;
    
cout << "~" << "\n";
}
    return 0;
}
// } Driver Code Ends
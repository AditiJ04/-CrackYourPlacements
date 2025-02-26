//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

int *constructST(int arr[],int n);


int RMQ(int st[] , int n, int a, int b);
int main()
{
    int T;
    cin>>T;
    while(T--)
    {
        int N;
        cin>>N;
        int A[N];
        for(int i=0;i<N;i++)
            cin>>A[i];
        int Q;
        cin>>Q;



        int *segTree = constructST(A,N);

        for(int i=0;i<Q;i++)
        {
            int start,e;
            
            cin>>start>>e;
            if(start>e)
            {
                swap(start,e);
            }
            cout<<RMQ(segTree,N,start,e)<<" ";
        }
        cout<<endl;
    
cout << "~" << "\n";
}
}

// } Driver Code Ends


/* The functions which 
builds the segment tree */
void buildTree(int arr[],int n,int sg[],int i,int s,int e)
{
    if(s==e)
    {
        sg[i]=arr[s];
        return;
    }
    int mid=s+(e-s)/2;;
    
    buildTree(arr,n,sg,2*i+1,s,mid);
    buildTree(arr,n,sg,2*i+2,mid+1,e);
    
    sg[i]=min(sg[2*i+1],sg[2*i+2]);
}
int query(int st[],int s,int e,int i,int l,int r)
{
    if(l>e || r<s)
    {
        return INT_MAX;
    }
    
    if(l>=s && r<=e)
    {
        return st[i];
    }
    int mid=l+(r-l)/2;
    return min(query(st,s,e,2*i+1,l,mid),query(st,s,e,2*i+2,mid+1,r));
}
int *constructST(int arr[],int n)
{
  //Your code here
  int *sg=new int[4*n];
  
  buildTree(arr,n,sg,0,0,n-1);
  
  return sg;
}

/* The functions returns the
 min element in the range
 from a and b */
int RMQ(int st[] , int n, int a, int b)
{
//Your code here
    return query(st,a,b,0,0,n-1);
}
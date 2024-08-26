//{ Driver Code Starts
// Initial template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function template in C++

class Solution {
  public:
    // Function to find minimum number of pages.
    long long findPages(int n, int arr[], int m) {
        // code here
        if(m>n)
        {
            return -1;
        }
        
        int s=0,e=0,mid,ans;
        
        for(int i=0;i<n;i++)
        {
            s=max(s,arr[i]);
            e+=arr[i];
        }
        
        while(s<=e)
        {
            mid=s+(e-s)/2;
            
            int pgs=0,cnt=1;
            
            for(int i=0;i<n;i++)
            {
                pgs+=arr[i];
                if(pgs>mid)
                {
                    cnt++;
                    pgs=arr[i];
                }
            }
            
            if(cnt<=m)
            {
                ans=mid;
                e=mid-1;
            }
            
            else
            {
                s=mid+1;
            }
        }
        
        return ans;
    }
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        int A[n];
        for (int i = 0; i < n; i++) {
            cin >> A[i];
        }
        int m;
        cin >> m;
        Solution ob;
        cout << ob.findPages(n, A, m) << endl;
    }
    return 0;
}

// } Driver Code Ends
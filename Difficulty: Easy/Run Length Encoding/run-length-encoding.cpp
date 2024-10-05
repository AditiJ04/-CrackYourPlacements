//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;


// } Driver Code Ends

class Solution {
  public:
    string encode(string s) {
        // code here
        
        string ans;
        int n=s.size();
        int cnt=1;
        int i;
        for(i=1;i<n;i++)
        {
            if(s[i]!=s[i-1])
            {
                ans.push_back(s[i-1]);
                ans+=to_string(cnt);
                cnt=1;
            }
            else
            {
                cnt++;
            }
        }
        ans.push_back(s[i-1]);
        ans+=to_string(cnt);
        return ans;
    }
};


//{ Driver Code Starts.

int main(){
    int t;
    scanf("%d ",&t);
    while(t--){
        
        string s;
        getline(cin,s);
        
        Solution obj;
        string res = obj.encode(s);
        
        cout<<res<<"\n";
        
    }
}

// } Driver Code Ends
//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function template for C++
//a-97 to z-122
//A-65 to Z-90
class Solution {
  public:
    /*You are required to complete this method */
    int atoi(string &s) {
        // Your code here
        int i;
        int n=s.size();
        int rem=0;
        int ans;
        
        if(s[0]=='-')
        {
            i=-1;
            
            for(int i=1;i<n;i++)
            {
                if(s[i]>=97 && s[i]<=122 || s[i]>=65 && s[i]<=90)
                {
                    return -1;
                }
                rem*=10;
                rem+=s[i]-'0';
            }
            ans=(-1)*rem;
        }
        
        else
        {
            for(int i=0;i<n;i++)
            {
                if(s[i]>=97 && s[i]<=122 || s[i]>=65 && s[i]<=90)
                {
                    return -1;
                }
                rem*=10;
                rem+=s[i]-'0';
            }
            ans=rem;
        }
        return ans;
    }
};

//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        string s;
        cin >> s;
        Solution ob;
        int ans = ob.atoi(s);
        cout << ans << endl;
    }
}
// } Driver Code Ends
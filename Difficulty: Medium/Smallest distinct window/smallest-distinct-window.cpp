//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution{
    public:
    int findSubString(string str)
    {
        // Your code goes here   
        int ans=INT_MAX;
        unordered_map<int,int>m;
        for(int i=0;i<str.length();i++)
        {
            m[str[i]]++;
        }
        int k=m.size();
        int i=0,j=0;
        m.clear();
        while(j<str.length())
        {
            m[str[j]]++;
            if(m.size()==k)
            {
                ans=min(ans,j-i+1);
                while(m.size()==k)
                {
                    ans=min(ans,j-i+1);
                    m[str[i]]--;
                    if(m[str[i]]==0)
                    {
                        m.erase(str[i]);
                    }
                    
                    i++;
                }
            }
            j++;
        }
        return ans;
    }
};

//{ Driver Code Starts.
// Driver code
int main() {
    int t;
    cin >> t;
    while (t--) {

        string str;
        cin >> str;
        Solution ob;
        cout << ob.findSubString(str) << endl;
    }
    return 0;
}
// } Driver Code Ends
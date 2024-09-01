//{ Driver Code Starts
#include <bits/stdc++.h>

using namespace std;


// } Driver Code Ends
//User function template for C++
class Solution{
public:
	int search(string pat, string txt) {
	    // code here
	    vector<int>Count(26,0);
	    
	    for(char &c:pat)
	    {
	        Count[c-'a']++;
	    }
	    int cnt=0;
	    
	    int n=txt.size();
	    int m=pat.size();
	    
	    int i=0,j=0;
	    
	    while(j<n)
	    {
	 
	         Count[txt[j]-'a']--;
	        
	        if(j-i+1==m)
	        {
	            if(Count==vector<int>(26,0))
	            {
	                cnt++;
	            }
	            Count[txt[i]-'a']++;
	            i++;
	        }
	        j++;
	        
	    }
	    
	    return cnt;
	}

};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        string pat, txt;
        cin >> txt >> pat;
        Solution ob;
        auto ans = ob.search(pat, txt);
        cout << ans << "\n";
    }
    return 0;
}
// } Driver Code Ends
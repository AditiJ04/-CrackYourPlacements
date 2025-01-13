//{ Driver Code Starts
#include <bits/stdc++.h>

using namespace std;


// } Driver Code Ends
// User function template for C++
class Solution {
  public:

    void matchPairs(int n, char nuts[], char bolts[]) {
        // code here
        char specialChars[] = { '!', '#', '$', '%', '&', '*', '?', '@', '^' };
        char narr[n];
        
        unordered_map<char,int>mp;
        
         for (int i = 0; i < n; i++) {
        mp[nuts[i]]++;
    }

        int j=0;
        for(int i=0;i<9;i++)
        {
            if(mp.find(specialChars[i])!=mp.end())
            {
                narr[j]=specialChars[i];
                j++;
            }
        }
       for (int i = 0; i < j; i++) {
        nuts[i] = narr[i];
        bolts[i] = narr[i];
       }
    }
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        char nuts[n], bolts[n];
        for (int i = 0; i < n; i++) {
            cin >> nuts[i];
        }
        for (int i = 0; i < n; i++) {
            cin >> bolts[i];
        }
        Solution ob;
        ob.matchPairs(n, nuts, bolts);
        for (int i = 0; i < n; i++) {
            cout << nuts[i] << " ";
        }
        cout << "\n";
        for (int i = 0; i < n; i++) {
            cout << bolts[i] << " ";
        }
        cout << "\n";
    
cout << "~" << "\n";
}
    return 0;
}

// } Driver Code Ends
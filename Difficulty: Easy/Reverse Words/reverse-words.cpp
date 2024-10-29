//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends

class Solution {
  public:
    // Function to reverse words in a given string.
    string reverseWords(string str) {
        // code here
        int n=str.size();
        
        vector<string>ans;
        
        stringstream ss(str);
        string word;
        
        string str1;
        
        while(getline(ss,word,'.'))
        {
            ans.push_back(word);
        }
        
        reverse(ans.begin(),ans.end());
        
        for(int i=0;i<ans.size();i++)
        {
            str1+=ans[i];
            
            if(i!=ans.size()-1)
            {
                str1+='.';
            }
        }
        
        return str1;
    }
};

//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        string s;
        cin >> s;
        Solution obj;
        cout << obj.reverseWords(s) << endl;

        cout << "~"
             << "\n";
    }
}
// } Driver Code Ends
//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution {
  public:
  
    vector<int>ans;
    
    void findSum(vector<int>arr,int sum,int idx)
    {
        ans.push_back(sum);
        for(int i=idx;i<arr.size();i++)
        {
            findSum(arr,sum+arr[i],i+1);
        }
    }
    vector<int> subsetSums(vector<int> arr, int n) {
        // Write Your Code here
        int sum=0;
        
        findSum(arr,sum,0);
        
        return ans;
    }
};

//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int N;
        cin >> N;
        vector<int> arr(N);
        for (int i = 0; i < N; i++) {
            cin >> arr[i];
        }
        Solution ob;
        vector<int> ans = ob.subsetSums(arr, N);
        sort(ans.begin(), ans.end());
        for (auto sum : ans) {
            cout << sum << " ";
        }
        cout << endl;
    
cout << "~" << "\n";
}
    return 0;
}
// } Driver Code Ends
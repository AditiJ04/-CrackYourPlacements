//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
  public:
   int m = 1000000000 + 7;

int CountSubsets(vector<int>& arr, int n, int sum, vector<vector<int>>& dp) {
    if (n == 0) {
        // Base case: if there's only one element, check subset possibilities
        if (sum == 0 && arr[0] == 0)
            return 2;  // two subsets: {} and {arr[0]}
        if (sum == 0 || sum == arr[0])
            return 1;
        return 0;
    }

    // Memoization check
    if (dp[n][sum] != -1) {
        return dp[n][sum];
    }

    // Calculate subsets including or excluding the current element
    int include = 0, exclude = 0;
    if (arr[n] <= sum) {
        include = CountSubsets(arr, n - 1, sum - arr[n], dp) % m;
    }
    exclude = CountSubsets(arr, n - 1, sum, dp) % m;

    // Store result in dp array and apply modulo
    return dp[n][sum] = (include + exclude) % m;
}

int countPartitions(int n, int d, vector<int>& arr) {
    int totalSum = 0;

    // Calculate total sum of elements
    for (int i = 0; i < n; i++) {
        totalSum += arr[i];
    }

    // Check if valid partition is possible
    if (totalSum - d < 0 || (totalSum - d) % 2 == 1) {
        return 0;
    }
    
    int targetSum = (totalSum - d) / 2;

    // Initialize dp array with -1 for memoization
    vector<vector<int>> dp(n, vector<int>(targetSum + 1, -1));

    // Call the recursive function starting from the last index
    return CountSubsets(arr, n - 1, targetSum, dp);
}
};

//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int n, d;
        cin >> n >> d;
        vector<int> arr;

        for (int i = 0; i < n; ++i) {
            int x;
            cin >> x;
            arr.push_back(x);
        }

        Solution obj;
        cout << obj.countPartitions(n, d, arr) << "\n";
    
cout << "~" << "\n";
}
    return 0;
}
// } Driver Code Ends
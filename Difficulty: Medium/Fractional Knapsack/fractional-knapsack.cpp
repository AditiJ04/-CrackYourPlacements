//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends

// class implemented
/*
struct Item{
    int value;
    int weight;
};
*/

class Solution {
  public:
    // Function to get the maximum total value in the knapsack.
    double fractionalKnapsack(vector<int>& val, vector<int>& wt, int capacity) {
        // Your code here
        int n=val.size();
        
       vector<pair<double, pair<int, int>>> v;  // Corrected vector declaration
    double ans = 0;  // Use double for fractional results

    // Calculate value-to-weight ratio and store it in the vector
    for (int i = 0; i < n; i++) {
        double ratio = (double)val[i] / wt[i];
        v.push_back({ratio, {val[i], wt[i]}});
    }
        
          sort(v.begin(), v.end(), [](const auto &a, const auto &b) {
        return a > b;  // Descending order based on first, then second, then third
    });
        int ncap=capacity;
        for(int i=0;i<n;i++)
        {
            pair<int,pair<int,int>>p=v[i];
            
            int wt=p.second.second;
            
            if(wt<=capacity)
            {
                ans+=p.second.first;
                capacity-=wt;
            }
            
            else
            {
               // int req=ncap-capacity;
                ans+=((double)(p.second.first)/(p.second.second))*capacity;
                break;
            }
        }
        
        return ans;
    }
};



//{ Driver Code Starts.

int main() {

    int t;
    // taking testcases
    cin >> t;
    cin.ignore(); // to ignore the newline after the number of test cases
    cout << setprecision(6) << fixed;

    while (t--) {
        // Reading the value array
        vector<int> values;
        string input;
        getline(cin, input);
        stringstream ss(input);
        int number;
        while (ss >> number) {
            values.push_back(number);
        }

        // Reading the weight array
        vector<int> weights;
        getline(cin, input);
        stringstream ss2(input);
        while (ss2 >> number) {
            weights.push_back(number);
        }

        // Reading the capacity
        int w;
        cin >> w;
        cin.ignore(); // to ignore the newline after capacity

        // function call
        Solution ob;
        cout << ob.fractionalKnapsack(values, weights, w) << endl;
        cout << "~" << endl;
    }
    return 0;
}

// } Driver Code Ends
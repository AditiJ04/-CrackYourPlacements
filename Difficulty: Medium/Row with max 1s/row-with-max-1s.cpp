//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends

// User function template for C++
class Solution {
  public:
    int findUB(vector<int>&arr,int s,int x)
    {
        int l=0;
        int h=s-1;
        int idx=s;
        
        while(l<=h)
        {
            int mid=l+(h-l)/2;
            
            if(arr[mid]>x)
            {
                idx=mid;
                h=mid-1;
            }
            else
            {
                l=mid+1;
            }
        }
        
        return idx;
    }
    int rowWithMax1s(vector<vector<int>> &arr) {
        // code here
        int n=arr.size();
        int m=arr[0].size();
        
        int cnt_max=0;
        int idx=-1;
        for(int i=0;i<n;i++)
        {
            int cnt=findUB(arr[i],m,0);
            int cnt_one=m-cnt;
            
            if(cnt_one>cnt_max)
            {
                cnt_max=cnt_one;
                idx=i;
            }
        }
        
        return idx;
    }
};


//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    cin.ignore(); // Ignore the newline character after the integer input
    while (t--) {
        string input;
        getline(cin, input);
        vector<vector<int>> mat;
        string innerArray;
        bool isInsideArray = false;

        for (char c : input) {
            if (c == '[') {
                if (isInsideArray) {
                    innerArray.clear();
                }
                isInsideArray = true;
            } else if (c == ']') {
                if (isInsideArray && !innerArray.empty()) {
                    vector<int> row;
                    stringstream ss(innerArray);
                    int num;

                    while (ss >> num) {
                        row.push_back(num);
                        if (ss.peek() == ',')
                            ss.ignore();
                        while (isspace(ss.peek()))
                            ss.ignore();
                    }

                    mat.push_back(row);
                    innerArray.clear();
                }
                isInsideArray = false;
            } else if (isInsideArray) {
                if (!isspace(c)) {
                    innerArray += c;
                }
            }
        }

        Solution obj;
        cout << obj.rowWithMax1s(mat);
        cout << endl;
        cout << "~" << endl;
    }
    return 0;
}

// } Driver Code Ends
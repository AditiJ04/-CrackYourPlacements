//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function template for C++

class Solution {
  public:
  
    int row[4]={0,-1,0,1};
    int col[4]={-1,0,1,0};
    char arr[4]={'L','U','R','D'};
    vector<string>ans;
    void Paths(vector<vector<int>>& mat, vector<vector<int>>& vis, int n, int i, int j, string& str)
{
    if (i == n - 1 && j == n - 1) // Reached destination
    {
        ans.push_back(str);
        return;
    }
    
    // Try all four directions
    for (int k = 0; k < 4; k++)
    {
        int r = i + row[k];
        int c = j + col[k];
        char ch = arr[k];
        
        // Check if the new position is within bounds and not visited and is a valid path (mat[r][c] == 1)
        if (r >= 0 && r < n && c >= 0 && c < n && mat[r][c] == 1 && !vis[r][c])
        {
            vis[r][c] = 1; // Mark the cell as visited
            str.push_back(ch);
            Paths(mat, vis, n, r, c, str);
            str.pop_back(); // Backtrack
            vis[r][c] = 0; // Unmark the cell after backtracking
        }
    }
}

    vector<string> findPath(vector<vector<int>> &mat) {
        // code here
        int n=mat.size();
       
        if(mat[0][0]==0)
        {
            return ans;
        }
        
        string str;
        
        vector<vector<int>>vis(n,vector<int>(n,0));
        
         vis[0][0]=1;
         
        Paths(mat,vis,n,0,0,str);
        
        return ans;
    }
};


//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    cin.ignore();
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
        vector<string> result = obj.findPath(mat);
        sort(result.begin(), result.end());

        if (result.empty())
            cout << "[]";
        else
            for (int i = 0; i < result.size(); i++)
                cout << result[i] << " ";
        cout << endl;
        cout << "~" << endl;
    }
    return 0;
}

// } Driver Code Ends
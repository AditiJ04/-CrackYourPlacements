1class Solution {
2public:
3    vector<vector<int>> minimumAbsDifference(vector<int>& arr) {
4        sort(arr.begin(),arr.end());
5
6        int n=arr.size();        
7        vector<vector<int>>ans;
8        int mn=INT_MAX;
9
10        for(int i=1;i<n;i++)
11        {
12            mn=min(mn,arr[i]-arr[i-1]);
13        }
14
15        for(int i=1;i<n;i++)
16        {
17            int diff=arr[i]-arr[i-1];
18            if(diff==mn)
19            {
20                ans.push_back({arr[i-1],arr[i]});
21            }
22        }
23
24        return ans;
25    }
26};
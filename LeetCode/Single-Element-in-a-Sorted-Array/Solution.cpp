1class Solution {
2public:
3    int singleNonDuplicate(vector<int>& arr) {
4        int n=arr.size();
5
6        if(n==1) return arr[0];
7        if(arr[0]!=arr[1]) return arr[0];
8        if(arr[n-1]!=arr[n-2]) return arr[n-1];
9
10        int l=1,h=n-2;
11        int ans;
12
13        while(l<=h)
14        {
15            int mid=(l+h)/2;
16
17            if(arr[mid]!=arr[mid-1] && arr[mid]!=arr[mid+1]) return ans=arr[mid];
18            if(mid%2==0)
19            {
20                if(arr[mid]==arr[mid+1]) l=mid+1;
21                else h=mid+1;
22            }
23
24            else if(mid%2!=0)
25            {
26                if(arr[mid]==arr[mid-1]) l=mid+1;
27                else
28                {
29                    h=mid-1;
30                }
31            }
32        }
33
34        return ans;
35    }
36};
1class Solution {
2public:
3    int minLength(vector<int>& nums, int k) {
4        int n=nums.size();
5        int mn=INT_MAX;
6
7        int sum=0;
8        int i=0,j=0;
9
10        unordered_map<int,int>mp;
11
12        while(i<n)
13        {
14            if(mp[nums[i]]==0)
15            {
16                sum+=nums[i];
17            }
18            mp[nums[i]]++;
19
20            while(sum>=k)
21            {
22                mn=min(mn,i-j+1);
23
24                mp[nums[j]]--;
25                if(mp[nums[j]]==0)
26                {
27                    sum-=nums[j];
28                }
29                j++;
30            }
31            i++;
32        }
33
34        return mn==INT_MAX?-1:mn;
35    }
36};
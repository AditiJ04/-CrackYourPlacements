1class Solution {
2public:
3    map<int,vector<int>>mp;
4
5    void findBin(int num)
6    {
7        int cnt=0;
8        int ori=num;
9        while(num!=0)
10        {
11            auto r=num%2;
12            if(r==1) cnt++;
13            num/=2;
14        }
15        mp[cnt].push_back(ori);
16    }
17    vector<int> sortByBits(vector<int>& arr) {
18        int n=arr.size();
19        vector<int>ans;
20        sort(arr.begin(),arr.end());
21
22        for(int i=0;i<n;i++)
23        {
24            findBin(arr[i]);
25        }
26
27        for(auto p:mp)
28        {
29            auto v=p.second;
30            for(auto val:v)
31            {
32                ans.push_back(val);
33            }
34        }
35
36        return ans;
37    }
38};
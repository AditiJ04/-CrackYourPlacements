1class Solution {
2public:
3    vector<int> toggleLightBulbs(vector<int>& bulbs) {
4        int n=bulbs.size();
5
6        unordered_map<int,int>mp;
7        vector<int>ans;
8
9        for(int i=0;i<n;i++)
10        {
11            if(mp.find(bulbs[i])==mp.end()) mp[bulbs[i]]++;
12            else
13            {
14                mp.erase(bulbs[i]);
15            }
16        }
17
18        for(auto it:mp)
19        {
20            ans.push_back(it.first);
21        }
22
23        sort(ans.begin(),ans.end());
24        return ans;
25    }
26};
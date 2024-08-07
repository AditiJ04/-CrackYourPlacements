class Solution {
public:
    int leastInterval(vector<char>& tasks, int n) {
        int s=tasks.size();
        unordered_map<char,int>mp;
        int cnt=0;
        for(int i=0;i<s;i++)
        {
            mp[tasks[i]]++;
            cnt=max(cnt,mp[tasks[i]]);
        }

        int ans=(cnt-1)*(n+1);

        for(auto e:mp)
        {
            if(e.second==cnt)
            {
                ans++;
            }
        }

        return max((int)tasks.size(),ans);
    }
};
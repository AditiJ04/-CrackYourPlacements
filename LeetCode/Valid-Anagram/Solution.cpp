class Solution {
public:
    bool isAnagram(string s, string t) {
        int n=s.size();

        if(s.size()!=t.size()) return false;

        unordered_map<char,int>mp;

        for(int i=0;i<n;i++)
        {
            mp[s[i]]++;
        }

        for(int i=0;i<t.size();i++)
        {
            if(mp.find(t[i])!=mp.end())
            {
                mp[t[i]]--;

                if(mp[t[i]]==0) mp.erase(t[i]);
            }
        }
        if(mp.empty()) return true;

        return false;
    }
};
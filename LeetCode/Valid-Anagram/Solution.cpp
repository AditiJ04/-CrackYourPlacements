class Solution {
public:
    bool isAnagram(string s, string t) {
        int n=s.size();
        int m=t.size();

        if(n>m)
        {
            return false;
        }

        unordered_map<char,int>mp;

        for(int i=0;i<n;i++)
        {
            mp[s[i]]++;
        }

        for(auto c:t)
        {
            if(mp.find(c)==mp.end())
            {
                return false;
            }
            mp[c]--;
            if(mp[c]==0)
            {
                mp.erase(c);
            }
        }

        return true;
    }
};
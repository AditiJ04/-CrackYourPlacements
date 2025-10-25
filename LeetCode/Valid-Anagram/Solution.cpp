class Solution {
public:
    bool isAnagram(string s, string t) {
        int n=s.size();
        int m=t.size();

        if(n!=m) return false;

        vector<int>v(26,0);

        for(int i=0;i<n;i++)
        {
            v[s[i]-'a']++;
        }

        for(int i=0;i<m;i++)
        {
            v[t[i]-'a']--;
        }

        return v==vector<int>(26,0);
    }
};
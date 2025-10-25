class Solution {
public:
    bool isAnagram(string s, string t) {
        unordered_map<char,int>mp1;
        unordered_map<char,int>mp2;

        for(int i=0;i<s.length();i++)
        {
            mp1[s[i]]++;
        }

         for(int i=0;i<t.length();i++)
        {
            mp2[t[i]]++;
        }

        for(auto c:mp2)
        {
            if(mp1[c.first]==c.second)
            {
                continue;
            }
            else
            {
                return false;
            }
        }

         for(auto c:mp1)
        {
            if(mp2[c.first]==c.second)
            {
                continue;
            }
            else
            {
                return false;
            }
        }
        return true;
    }
};
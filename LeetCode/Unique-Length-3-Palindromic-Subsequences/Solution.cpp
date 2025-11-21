class Solution {
public:
    int countPalindromicSubsequence(string s) {
        int n=s.size();
        int res=0;

        vector<pair<int,int>>v(26,{-1,-1});

        for(int i=0;i<n;i++)
        {
            char ch=s[i];

            int idx=ch-'a';

            if(v[idx].first==-1)
            {
                v[idx].first=i;
            }
            v[idx].second=i;
        }

        for(int i=0;i<26;i++)
        {
            int f_idx=v[i].first;
            int l_idx=v[i].second;

            if(f_idx==-1 && l_idx==-1) continue;

            unordered_set<char>st;
            for(int j=f_idx+1;j<=l_idx-1;j++)
            {
                st.insert(s[j]);
            }

            res+=st.size();
        }

        return res;
    }
};
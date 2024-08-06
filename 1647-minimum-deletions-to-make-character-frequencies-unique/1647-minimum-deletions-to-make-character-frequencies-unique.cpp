class Solution {
public:
    int minDeletions(string s) {
        int n=s.length();
        int del=0;

        unordered_map<char,int>mp;

        for(int i=0;i<s.length();i++)
        {
            mp[s[i]]++;
        }

        vector<int>ans;

        for(auto it:mp)
        {
            ans.push_back(it.second);
        }

        bool flg=false;
        int idx=0;
        sort(ans.begin(),ans.end(),greater<int>());

        for(int i=0;i<ans.size()-1;i++)
        {
            if(ans[i]==0)
            {
                flg=true;
                idx=i;
                break;
            }
            if(ans[i]==ans[i+1])
            {
                ans[i+1]-=1;
                del++;
            }
            else
            {
                if(ans[i]<ans[i+1])
                {
                    int diff=(ans[i+1]-ans[i])+1;
                    del+=diff;
                    ans[i+1]=ans[i+1]-diff;
                }
            }
        }

        if(flg)
        {
            for(int i=idx;i<ans.size();i++)
            {
                del+=ans[i];
            }
        }
        return del;
    }
};
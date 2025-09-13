class Solution {
public:
    int maxFreqSum(string s) {
        int n=s.size();

        unordered_map<char,int>mp;

        for(int i=0;i<n;i++)
        {
            mp[s[i]]++;
        }

        int mxv=0,mxc=0;
        for(auto it:mp)
        {
            char c=it.first;

            if(c=='a' || c=='e' || c=='i' || c=='o' || c=='u') mxv=max(mxv,it.second);
            else mxc=max(mxc,it.second);
        }

        return mxv+mxc;
    }
};
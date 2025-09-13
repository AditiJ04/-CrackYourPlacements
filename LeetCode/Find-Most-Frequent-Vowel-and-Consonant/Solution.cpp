class Solution {
public:
    int maxFreqSum(string s) {
        int n=s.size();

        unordered_map<char,int>vow;
        unordered_map<char,int>cons;

        int mxvow=0;
        int mxcon=0;

        for(int j=0;j<n;j++)
        {
            if(s[j]=='a' || s[j]=='e' || s[j]=='i' || s[j]=='o' || s[j]=='u')
            {
                vow[s[j]]++;
                mxvow=max(mxvow,vow[s[j]]);
            }
            else
            {
                cons[s[j]]++;
                mxcon=max(mxcon,cons[s[j]]);
            }
        }

        return mxvow+mxcon;
    }
};
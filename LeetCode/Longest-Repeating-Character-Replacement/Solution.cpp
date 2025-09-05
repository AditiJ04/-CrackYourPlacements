class Solution {
public:
    int characterReplacement(string s, int k) {

        vector<int>hash(26);
        int n=s.length();
        int l=0,r=0,mxfreq=0;
        int mxlen=0;
        while(r<n)
        {
            hash[s[r]-'A']++;
            mxfreq=max(mxfreq,hash[s[r]-'A']);

            if((r-l+1)-mxfreq>k)
            {
                hash[s[l]-'A']--;
              /*  mxfreq=0;

                for(int i=0;i<26;i++)
                {
                    mxfreq=max(mxfreq,hash[i]);
                }*/
                l++;
            }

            if((r-l+1)-mxfreq<=k)
            {
                mxlen=max(mxlen,r-l+1);
            }
            r++;
        }

        return mxlen;
    }
};
class Solution {
public:
    vector<int> findAnagrams(string s, string p) {
        int n=s.size();
        int m=p.size();

        vector<int>v(26,0);

        for(int i=0;i<m;i++)
        {
            v[p[i]-'a']++;
        }

        int k=0,j=0;

        vector<int>ans;

        while(j<n)
        {
            v[s[j]-'a']--;

            if(j-k+1==m)
            {
                if(v==vector<int>(26,0))
                {
                    ans.push_back(k);
                }
                v[s[k]-'a']++;
                k++;
            }
            j++;
        }

        return ans;
    }
};
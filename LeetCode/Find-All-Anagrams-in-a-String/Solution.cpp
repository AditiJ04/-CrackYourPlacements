class Solution {
public:
    vector<int> findAnagrams(string s, string p) {
        int n=s.size();
        int m=p.size();

        vector<int>ans;

        vector<int>v(26,0);
        for(int i=0;i<m;i++)
        {
            v[p[i]-'a']++;
        }

        int i=0,j=0;

        while(j<n)
        {
            v[s[j]-'a']--;

            if((j-i+1)==m)
            {
                if(v==vector<int>(26,0)) 
                {
                    ans.push_back(i);
                }
                v[s[i]-'a']++;
                i++;
            }
            j++;
        }

        return ans;
    }
};
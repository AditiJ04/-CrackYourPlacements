class Solution {
public:
    bool canConvertString(string s, string t, int k) {
        int n=s.size();
        int m=t.size();

        if(n!=m) return false;

        unordered_map<int,int>used;

        for(int i=0;i<n;i++)
        {
            if(s[i]!=t[i])
            {
                int moves_req=(t[i]-s[i]+26)%26;

                int move=moves_req+26*used[moves_req];
                if(move>k) return false;

                used[moves_req]++;
            }
        }
return true;
    }
};
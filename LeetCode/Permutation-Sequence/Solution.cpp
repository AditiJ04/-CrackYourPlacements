class Solution {
public:
    string getPermutation(int n, int k) {
        vector<int>ans;

        for(int i=1;i<=n;i++)
        {
            ans.push_back(i);
        }

        for(int i=2;i<=k;i++)
        {
            next_permutation(ans.begin(),ans.end());
        }

        string res="";
        for(int i=0;i<ans.size();i++)
        {
            res+=ans[i]+'0';
        }

        return res;
    }
};
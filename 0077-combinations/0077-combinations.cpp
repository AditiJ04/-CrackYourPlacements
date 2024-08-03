class Solution {
public:
    void Combine(vector<vector<int>>&res,vector<int>tmp,int s,int num,int n,int k)
    {
        if(num==k)
        {
            res.push_back(tmp);
            return;
        }

        for(int i=s;i<n;i++)
        {
            tmp.push_back(i+1);
            Combine(res,tmp,i+1,num+1,n,k);
            tmp.pop_back();
        }
    }
    vector<vector<int>> combine(int n, int k) {
        vector<vector<int>>res;

        if(n<k)
        {
            return res;
        }

        vector<int>tmp(0,k);

        Combine(res,tmp,0,0,n,k);

        return res;
    }
};
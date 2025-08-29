class Solution {
public:

    long long mxpro=0;
    void findMaximumProduct(int n,vector<int>&v,long long pro,int st)
    {
        if(n==0)
        {
            if(v.size()<2) return;
            else
            {
                mxpro=max(mxpro,pro);
            }
            return;
        }
        if(st>n) return;

        if(st<=n)
        {
            v.push_back(st);
            findMaximumProduct(n-st,v,pro*st,st);
            v.pop_back();
        }
        findMaximumProduct(n,v,pro,st+1);
    }
    int integerBreak(int n) {

        vector<int>v;

        long long pro=1;
        findMaximumProduct(n,v,pro,1);

        return (int)mxpro;
    }
};
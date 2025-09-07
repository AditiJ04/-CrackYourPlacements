class Solution {
public:
    vector<int> sumZero(int n) {

        if(n==1) return {0};
        vector<int>v;
        if(n%2==0)
        {
            for(int i=1;i<=n/2;i++)
            {
                v.push_back(i);
                v.push_back(-1*i);
            }
        }
        else
        {
            v.push_back(-1*n);
            v.push_back(1);
            v.push_back(n-1);

            int j=2;
            for(int i=1;i<=(n-3)/2;i++)
            {
                v.push_back(j);
                v.push_back(-1*j);
                j++;
            }
        }

        return v;
    }
};
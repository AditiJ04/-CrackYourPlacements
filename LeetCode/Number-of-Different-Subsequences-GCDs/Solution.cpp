class Solution {
public:
    int countDifferentSubsequenceGCDs(vector<int>& nums) {
        int n=nums.size();
        int ans=0;
        int max_ele=*max_element(nums.begin(),nums.end());


        vector<bool>v(max_ele+1,false);

        for(auto num:nums) v[num]=true;

        for(int i=1;i<=max_ele;i++)
        {
            int g=0;
            for(int j=i;j<=max_ele;j+=i)
            {
                if(v[j])
                {
                    g=gcd(g,j);
                }

                if(g==i) break;
            }
            if(g==i) ans++;
        }

        return ans;
    }
};
class Solution {
public:
    int maxDistinctElements(vector<int>& nums, int k) {
        int n=nums.size();

        int cnt=0;
        sort(nums.begin(),nums.end());

        int nxt=INT_MIN;

        for(int i=0;i<n;i++)
        {
            int l=(nums[i]-k);
            int h=(nums[i]+k);

            if(nxt<l)
            {
                nxt=l;
            }
            if(nxt<=h)
            {
                cnt++;
                nxt++;
            }
        }

        return cnt;
    }
};
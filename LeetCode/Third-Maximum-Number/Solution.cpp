class Solution {
public:
    int thirdMax(vector<int>& nums) {
        int n=nums.size();
        set<int>s;
      //  sort(nums.begin(),nums.end());

        for(int i=0;i<n;i++)
        {
            s.insert(nums[i]);
        }
        vector<int>v(s.begin(),s.end());
        sort(v.begin(),v.end(),greater<int>());

        if(v.size()>=3)
        {
            return v[2];
        }
        else
        {
            return v[0];
        }

    }
};
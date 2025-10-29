class Solution {
public:
    vector<int> majorityElement(vector<int>& nums) {
        vector<int>element;

        map<int,int>mp;

        int n=nums.size();

        int k=floor(n/3);

        for(int i=0;i<n;i++)
        {
            mp[nums[i]]++;
        }
        
        for(auto c:mp)
        {
            if(c.second>k)
            {
                element.push_back(c.first);
            }
        }
        return element;
    }
};
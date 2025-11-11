class Solution {
public:
    vector<int> intersection(vector<int>& nums1, vector<int>& nums2) {
        map<int,int>mp1;
        map<int,int>mp2;

        vector<int>v;

        for(int i=0;i<nums1.size();i++)
        {
            mp1[nums1[i]]++;
        }

        for(int i=0;i<nums2.size();i++)
        {
            mp2[nums2[i]]++;
        }
        for(auto c:mp1)
        {
            int k=c.first;
            if(mp2.find(k)!=mp2.end())
            {
                v.push_back(k);
            }
        }

        return v;
    }
};
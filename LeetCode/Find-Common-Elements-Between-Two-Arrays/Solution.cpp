class Solution {
public:
    vector<int> findIntersectionValues(vector<int>& nums1, vector<int>& nums2) {
        map<int,int>mp1;
        map<int,int>mp2;

        int cnt1=0;
        int cnt2=0;

        vector<int>v(2,0);

        for(int i=0;i<nums1.size();i++)
        {
            mp1[nums1[i]]++;
        }

        for(int i=0;i<nums2.size();i++)
        {
            mp2[nums2[i]]++;
        }

        for(int i=0;i<nums2.size();i++)
        {
            if(mp1[nums2[i]]>=1)
            {
                v[1]++;
            }
        }

        for(int i=0;i<nums1.size();i++)
        {
            if(mp2[nums1[i]]>=1)
            {
                v[0]++;
            }
        }
       
        return v;
    }
};
class Solution {
public:
    vector<int> findIntersectionValues(vector<int>& nums1, vector<int>& nums2) {
        unordered_map<int,int>mp1;
        unordered_map<int,int>mp2;

        int n=nums1.size();
        int m=nums2.size();

        for(int i=0;i<n;i++)
        {
            mp1[nums1[i]]++;
        }

        for(int i=0;i<m;i++)
        {
            mp2[nums2[i]]++;
        }

        int c1=0,c2=0;

        for(int i=0;i<n;i++)
        {
            if(mp2.find(nums1[i])!=mp2.end()) c1++;
        }
        for(int i=0;i<m;i++)
        {
            if(mp1.find(nums2[i])!=mp1.end()) c2++;
        }

        return {c1,c2};
    }
};

// 2 2 3
// 1 2
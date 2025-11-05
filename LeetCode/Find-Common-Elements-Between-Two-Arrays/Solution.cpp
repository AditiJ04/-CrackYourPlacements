class Solution {
public:
    vector<int> findIntersectionValues(vector<int>& nums1, vector<int>& nums2) {
        map<int,int>mp1;
        map<int,int>mp2;

        vector<int>ans(2,0);
        for(int i=0;i<nums1.size();i++)
        {
            mp1[nums1[i]]++;
        }

          for(int i=0;i<nums2.size();i++)
        {
            mp2[nums2[i]]++;
        }
        for(int j=0;j<nums2.size();j++)
        {
            if(mp1[nums2[j]]>0)
            {
                ans[1]++;
            }
        }
        //ans.push_back(c1);
          for(int j=0;j<nums1.size();j++)
        {
            
                if(mp2[nums1[j]]>0)
                {
                ans[0]++;
                }
            
        }
     //  sort(ans.begin(),ans.end());
        return ans;
        
      //  vector<int>ans;
    }
};
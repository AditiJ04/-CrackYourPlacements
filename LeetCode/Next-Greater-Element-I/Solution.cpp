class Solution {
public:
    vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2) {
        vector<int>v;
        stack<int>s;
        for(int i=nums2.size()-1;i>=0;i--)
        {
           while(!s.empty() && s.top()<=nums2[i])
           {
               s.pop();
           }
           if(!s.empty() && s.top()>nums2[i])
           {
               v.push_back(s.top());
           }
           else
           {
               v.push_back(-1);
           }
           s.push(nums2[i]);
        }
        reverse(v.begin(),v.end());

        vector<int>ans;
        for(int i=0;i<nums1.size();i++)
        {
            for(int j=0;j<nums2.size();j++)
            {
                if(nums1[i]==nums2[j])
                {
                    ans.push_back(v[j]);
                }
            }
        }
        return ans;
    }
};
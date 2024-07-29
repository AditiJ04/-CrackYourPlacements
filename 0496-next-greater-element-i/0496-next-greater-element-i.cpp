class Solution {
public:
    vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2) {

        stack<int>st;
        vector<int>ans;
        for(int i=nums2.size()-1;i>=0;i--)
        {
            while(!st.empty() && nums2[i]>=st.top())
            {
                st.pop();
            }

            if(!st.empty() && nums2[i]<=st.top())
            {
                ans.push_back(st.top());
            }

            else
            {
                ans.push_back(-1);
            }
            st.push(nums2[i]);
        }

        reverse(ans.begin(),ans.end());
    
    vector<int>res;
    for(int i=0;i<nums1.size();i++)
    {
        for(int j=0;j<nums2.size();j++)
        {
            if(nums1[i]==nums2[j])
            {
                res.push_back(ans[j]);
            }
        }
    }

    return res;

    }

};
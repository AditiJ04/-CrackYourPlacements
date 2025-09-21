class Solution {
public:
    vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2) {
        int n=nums2.size();

        unordered_map<int,int>mp;
        stack<int>st;
        st.push(n-1);
        for(int i=n-2;i>=0;i--)
        {
            while(!st.empty() && nums2[i]>nums2[st.top()])
            {
                st.pop();
            }

            if(!st.empty() && nums2[i]<nums2[st.top()]) mp[nums2[i]]=nums2[st.top()];

            if(st.empty() || nums2[st.top()]>nums2[i])
            {
                st.push(i);
            }
        }

        vector<int>ans;

        for(int i=0;i<nums1.size();i++)
        {
            if(mp.find(nums1[i])!=mp.end())
            {
                ans.push_back(mp[nums1[i]]);
            }
            else
            {
                ans.push_back(-1);
            }
        }
        return ans;
    }
};
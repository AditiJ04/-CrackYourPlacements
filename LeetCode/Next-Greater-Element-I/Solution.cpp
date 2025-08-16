class Solution {
public:
    vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2) {
        int m=nums1.size();
        int n=nums2.size();

        vector<int>nge(n,-1);

        stack<int>st;
        unordered_map<int,int>mp;

        mp[nums2[n-1]]=-1;
        st.push(nums2[n-1]);
        for(int i=n-2;i>=0;i--)
        {
            while(!st.empty() && nums2[i]>st.top())
            {
                st.pop();
            }
            if(st.empty())
            {
                nge[i]=-1;
            }
            else
            {
                nge[i]=st.top();
            }
            st.push(nums2[i]);
            mp[nums2[i]]=nge[i];
        }

        vector<int>res(m,-1);

        for(int i=0;i<nums1.size();i++)
        {
            res[i]=mp[nums1[i]];
        }

        return res;
    }
};
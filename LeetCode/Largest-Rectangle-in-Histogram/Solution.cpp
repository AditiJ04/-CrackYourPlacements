class Solution {
public: 
    vector<int> NSL(vector<int>&heights,stack<int>&st)
    {
        vector<int>ans(heights.size(),0);
    
            for(int i=0;i<heights.size();i++)
            {
                while(!st.empty() && heights[st.top()]>=heights[i])
                {
                    st.pop();
                }
                if(st.empty())
                {
                    ans[i]=-1;
                }
                else
                {
                    ans[i]=st.top();
                }
                st.push(i);
            }
        return ans;
    }

     vector<int> NSR(vector<int>&heights,stack<int>&st)
    {
         vector<int>ans(heights.size(),heights.size()-1);
        int n=heights.size();
        
            for(int i=n-1;i>=0;i--)
            {
                while(!st.empty() && heights[st.top()]>=heights[i])
                {
                    st.pop();
                }
                if(st.empty())
                {
                    ans[i]=n;
                }
                else
                {
                    ans[i]=st.top();
                }
                st.push(i);
            }
        //reverse(ans.begin(),ans.end());
        return ans;
    }


    int largestRectangleArea(vector<int>& heights) {
        stack<int>st;

        int n=heights.size();

        vector<int>nsl=NSL(heights,st);
        
        while(!st.empty())
        {
            st.pop();
        }
        vector<int>nsr=NSR(heights,st);
    

        int mx=0;

        for(int i=0;i<n;i++)
        {
            mx=max(mx,heights[i]*(nsr[i]-nsl[i]-1));
        }

        return mx;
    }
};
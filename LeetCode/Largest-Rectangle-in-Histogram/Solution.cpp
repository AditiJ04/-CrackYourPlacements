class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {
        int n=heights.size();

        vector<int>nsr(n,0);
        vector<int>nsl(n,0);

        nsr[n-1]=n;
        nsl[0]=-1;

        stack<int>st;
        st.push(n-1);
        for(int i=n-2;i>=0;i--)
        {
            while(!st.empty() && heights[st.top()]>=heights[i])
            {
                st.pop();
            }
            if(st.empty())
            {
                nsr[i]=n;
            }
            else
            {
                nsr[i]=st.top();
            }
            st.push(i);
        }

        while(!st.empty()) st.pop();

        nsl[0]=-1;
        st.push(0);

        for(int i=1;i<n;i++)
        {
            while(!st.empty() && heights[st.top()]>=heights[i])
            {
                st.pop();
            }
            if(st.empty())
            {
                nsl[i]=-1;
            }
            else
            {
                nsl[i]=st.top();
            }
            st.push(i);
        }

        int mxans=INT_MIN;

        for(int i=0;i<n;i++)
        {
            mxans=max(mxans,(nsr[i]-nsl[i]-1)*heights[i]);
        }

        return mxans;
    }
};
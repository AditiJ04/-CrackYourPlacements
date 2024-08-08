class Solution {
public:
    int minCost(string colors, vector<int>& neededTime) {
        stack<pair<char,int>>st;

        int mincost=0;

        int n=colors.size();
        int m=neededTime.size();
        for(int i=0;i<n;i++)
        {
            if(st.empty()) 
            {
                st.push({colors[i],neededTime[i]});
            }

            else
            {
                if(st.top().first==colors[i])
                {
                    if(st.top().second>neededTime[i])
                    {
                        mincost+=neededTime[i];
                    }
                    else
                    {
                        mincost+=st.top().second;
                        st.pop();
                        st.push({colors[i],neededTime[i]});
                    }
                }

                else
                {
                    st.push({colors[i],neededTime[i]});
                }
            }
        }

        return mincost;
    }
};
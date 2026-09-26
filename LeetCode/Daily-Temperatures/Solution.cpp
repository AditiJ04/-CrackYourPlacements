1class Solution {
2public:
3    vector<int> dailyTemperatures(vector<int>& temperatures) {
4        int n=temperatures.size();
5
6        vector<int>ans(n,0);
7        stack<int>st;
8
9        st.push(0);
10
11        for(int i=1;i<n;i++)
12        {
13            if(temperatures[i]<temperatures[st.top()])
14            {
15                st.push(i);
16            }
17            else
18            {
19                while(!st.empty() && temperatures[i]>temperatures[st.top()])
20                {
21                    ans[st.top()]=i-st.top();
22                    st.pop();
23                }
24                st.push(i);
25            }
26        }
27
28        return ans;
29    }
30};
1class Solution {
2public:
3
4     int largestRectangleArea(vector<int>& heights) {
5        int n=heights.size();
6
7        vector<int>nsr(n,0);
8        vector<int>nsl(n,0);
9
10        nsr[n-1]=n;
11        nsl[0]=-1;
12
13        stack<int>st;
14        st.push(n-1);
15        for(int i=n-2;i>=0;i--)
16        {
17            while(!st.empty() && heights[st.top()]>=heights[i])
18            {
19                st.pop();
20            }
21            if(st.empty())
22            {
23                nsr[i]=n;
24            }
25            else
26            {
27                nsr[i]=st.top();
28            }
29            st.push(i);
30        }
31
32        while(!st.empty()) st.pop();
33
34        nsl[0]=-1;
35        st.push(0);
36
37        for(int i=1;i<n;i++)
38        {
39            while(!st.empty() && heights[st.top()]>=heights[i])
40            {
41                st.pop();
42            }
43            if(st.empty())
44            {
45                nsl[i]=-1;
46            }
47            else
48            {
49                nsl[i]=st.top();
50            }
51            st.push(i);
52        }
53
54        int mxans=INT_MIN;
55
56        for(int i=0;i<n;i++)
57        {
58            mxans=max(mxans,(nsr[i]-nsl[i]-1)*heights[i]);
59        }
60
61        return mxans;
62    }
63    int maximalRectangle(vector<vector<char>>& matrix) {
64        int n=matrix.size();
65        int m=matrix[0].size();
66
67        vector<int>v(m,0);
68        int mx=0;
69
70        for(int i=0;i<n;i++)
71        {
72            for(int j=0;j<m;j++)
73            {
74                if(matrix[i][j]=='1')
75                {
76                    v[j]++;
77                }
78                else
79                {
80                    v[j]=0;
81                }
82            }
83            mx=max(mx,largestRectangleArea(v));
84        }
85
86        return mx;
87    }
88};
1class Solution {
2public:
3    int countCoveredBuildings(int n, vector<vector<int>>& buildings) {
4
5        int m=buildings.size();
6        vector<pair<int,int>>row(n,{INT_MAX,INT_MIN});
7        vector<pair<int,int>>col(n,{INT_MAX,INT_MIN});
8
9        int cnt=0;
10        for(int i=0;i<m;i++)
11        {
12            int r=buildings[i][0]-1;
13            int c=buildings[i][1]-1;
14
15            row[r].first=min(c,row[r].first);
16            row[r].second=max(c,row[r].second);
17
18            col[c].first=min(r,col[c].first);
19            col[c].second=max(r,col[c].second);
20        }
21
22        for(int i=0;i<m;i++)
23        {
24            int r=buildings[i][0]-1;
25            int c=buildings[i][1]-1;
26
27            if(r>col[c].first && r<col[c].second && c>row[r].first && c<row[r].second) cnt++;
28        }
29        return cnt;
30    }
31};
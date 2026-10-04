1/*
2// Definition for Employee.
3class Employee {
4public:
5    int id;
6    int importance;
7    vector<int> subordinates;
8};
9*/
10
11class Solution {
12public:
13
14    unordered_map<int,int>mp;
15   
16    int findTotalImportance(vector<vector<int>>&adj,int id)
17    {
18        int total=0;
19        for(auto &it:adj[id])
20        {
21            if(mp.find(it)!=mp.end())
22            {
23                total+=mp[it];
24                mp.erase(it);
25                total+=findTotalImportance(adj,it);
26            }
27        }
28        return total;
29    }
30    int getImportance(vector<Employee*> employees, int id) {
31        int n=employees.size();
32
33        for(int i=0;i<n;i++)
34        {
35            int Id=employees[i]->id;
36            int imp=employees[i]->importance;
37
38            mp[Id]=imp;
39        }
40
41        vector<vector<int>>adj(2001);
42
43        for(int i=0;i<n;i++)
44        {
45            int id=employees[i]->id;
46            vector<int>sub=employees[i]->subordinates;
47
48            adj[id]=sub;
49        }
50
51        return mp[id]+findTotalImportance(adj,id);
52    }
53};
  if(ind==n)
  {
    return 0;
  }
  if(dp[ind]!=-1)
  {
    return dp[ind];
  }
  int nextInd =  lower_bound(sT.begin(),sT.end(), jobs[ind][1])-sT.begin();
   
  int mx =max(findMaxProf(jobs,sT,ind+1,n), jobs[ind][2]+findMaxProf(jobs,sT,nextInd,n));
  return  dp[ind]=mx; 
}
int jobScheduling(vector<int>& sT, vector<int>& eT, vector<int>& p) {
    
    memset(dp,-1,sizeof(dp));
    vector<vector<int>>jobs;
    int n=p.size();
    for(int i=0;i<p.size();i++)
    {
        jobs.push_back({sT[i],eT[i],p[i]});
    }

    sort(jobs.begin(),jobs.end());

    for(int i=0;i<jobs.size();i++)
    {
        sT[i]= jobs[i][0];
    }

    return findMaxProf(jobs,sT,0,n);
}
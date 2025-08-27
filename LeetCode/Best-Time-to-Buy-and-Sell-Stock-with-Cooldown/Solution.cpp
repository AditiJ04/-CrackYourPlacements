int solve(int buyedStock,int i,vector<int>&prices){
    if(i>=prices.size()){
        return 0;
    }
    if(buyedStock==-1){
        buyedStock=prices[i];
    }
    if(dp[i]!=-1) return dp[i];
    int notbought=solve(-1,i+1,prices);
    int sold=prices[i]-buyedStock+solve(-1,i+2,prices);
    int notSold=solve(buyedStock,i+1,prices);
    return dp[i]=max({sold,notSold,notbought});
}
class Solution {
public:
int rec(int i,vector<int>&a,int k,vector<vector<int>>&dp){
    if(i>=a.size()){return 0;}
    if(dp[i][k]!=-1){return dp[i][k];}
    int buy=0;int sell=0;
    if(k==0){
      buy = rec(i+1,a,k^1,dp)-a[i];
    }
    else{
        sell = a[i] + rec(i+2,a,k^1,dp);
    }
   int skip = rec(i+1,a,k,dp);
   if(k==1)dp[i][k] = max(sell,skip);
   else dp[i][k] = max(buy,skip);
   return dp[i][k];
}
    int maxProfit(vector<int>& a) {
        vector<vector<int>>dp(a.size(),vector<int>(2,-1));
        return rec(0,a,0,dp);
    }
};
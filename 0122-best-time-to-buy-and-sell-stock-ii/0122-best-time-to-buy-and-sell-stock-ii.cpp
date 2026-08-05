class Solution {
public:
int rec(int i,int k,vector<int>&a,vector<vector<int>>&dp){
 if(i>=a.size())return 0;
 int buy = 0;int sell =0 ;int skip =0;
 if(dp[i][k]!=-1)return dp[i][k];
    if(k==0) buy = rec(i+1,k^1,a,dp)-a[i];
    else  sell = rec(i+1,k^1,a,dp)+a[i];
     skip = rec(i+1,k,a,dp);
    return dp[i][k]=max({buy,sell,skip});
}
    int maxProfit(vector<int>& a) {
        vector<vector<int>>dp(a.size(),vector<int>(2,-1));
        return rec(0,0,a,dp);
    }
};
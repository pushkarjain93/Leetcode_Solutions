class Solution {
public:
int total(int i,int j,vector<int>&a,vector<vector<int>>&dp){
   if(i>j)return 0;
   if(dp[i][j]!=-1)return dp[i][j];
   //Alice has choice to pick first one so
  int first = a[i]+min(total(i+2,j,a,dp),total(i+1,j-1,a,dp));
   //if alice picks last one so
   int second = a[j]+min(total(i+1,j-1,a,dp),total(i,j-2,a,dp));
   return dp[i][j]=max(first,second);
}
    bool stoneGame(vector<int>& a) {
        int s = accumulate(a.begin(),a.end(),0);
        vector<vector<int>>dp(a.size(),vector<int>(a.size(),-1));
        int x = total(0,a.size()-1,a,dp);
        if(x>s-x)return true;
        return false;
    }
};
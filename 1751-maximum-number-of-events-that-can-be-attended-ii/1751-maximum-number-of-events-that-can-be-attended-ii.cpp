class Solution {
public:
int ans (int i,vector<int>&a,vector<int>&b,vector<int>&c,vector<vector<int>>&dp,int k){
    if(i>=a.size() || k==0){return 0;}
    if(dp[i][k]!=-1)return dp[i][k];
    int x = upper_bound(a.begin(),a.end(),b[i])-a.begin();
    int pick = c[i]+ans(x,a,b,c,dp,k-1);
    int notpick = ans(i+1,a,b,c,dp,k);
    return dp[i][k]=max(pick,notpick);
}
    int maxValue(vector<vector<int>>& v, int k) {
         sort(v.begin(),v.end());
         vector<int>a(v.size());
         vector<int>b(v.size());
         vector<int>c(v.size());
         vector<vector<int>>dp(a.size(),vector<int>(k+1,-1));
          for(int i=0;i<v.size();i++){
            a[i]=v[i][0];
            b[i]=v[i][1];
            c[i]=v[i][2];
        }
  return ans(0,a,b,c,dp,k);
    }
};
class Solution {
public:
 int p (int i,int j ,vector<int>&a,vector<vector<int>>&dp){
    if(j<0 ||i>=a.size() || i>j)return 0;
    if(dp[i][j]!=-1)return dp[i][j];
    // if A picks i then
    int x = a[i]+min(p(i+2,j,a,dp),p(i+1,j-1,a,dp));
    // if A picks j then
    int y = a[j]+min(p(i+1,j-1,a,dp),p(i,j-2,a,dp));
    return dp[i][j]=max(x,y);
 }
    bool predictTheWinner(vector<int>& a) {
        int n = a.size();
        vector<vector<int>>dp(n,vector<int>(n,-1));
        int x = (p(0,a.size()-1,a,dp));
        int s = accumulate(a.begin(),a.end(),0);
        if(x >= (s-x)){return true;}
        return false;
    }
};
class Solution {
public:
int r(int i,int j,string &s,string &t,vector<vector<int>>&dp){
    if(j==t.size())return 1;
    if(i==s.size())return 0;
    if(dp[i][j]!=-1)return dp[i][j];
    int x = 0;
    if(s[i]==t[j]){
       x = r(i+1,j+1,s,t,dp);
    }
  int y = r(i+1,j,s,t,dp);
    return dp[i][j]=(x+y);

}
    int numDistinct(string s, string t) {
        vector<vector<int>>dp(s.size(),vector<int>(t.size(),-1));
        return r(0,0,s,t,dp);
    }
};
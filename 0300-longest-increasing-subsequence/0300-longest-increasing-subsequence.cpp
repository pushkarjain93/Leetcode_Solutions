class Solution {
public:
int rec(int i,int prev,vector<int>&a,vector<vector<int>>&dp){
     if(i==a.size())return 0;
     if(prev>=0 && dp[i][prev]!=-1){
        return dp[i][prev];
     }
     int x = 0;
     int y = 0;
     if(prev<0){
         x = 1+rec(i+1,i,a,dp);
     }
     else if(prev>=0){
        if(a[i]>a[prev])x = 1+rec(i+1,i,a,dp);
     }
     y = rec(i+1,prev,a,dp);
     if(prev>=0){return dp[i][prev]=max(x,y);}
     return max(x,y);
}
    int lengthOfLIS(vector<int>& a) {
        vector<vector<int>>dp(a.size(),vector<int>(a.size()+1,-1));
        return rec(0,-1,a,dp);
    }
};
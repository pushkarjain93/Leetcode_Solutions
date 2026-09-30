class Solution {
public:
    int maximalSquare(vector<vector<char>>& a) {
        vector<vector<int>>dp(a.size(),vector<int>(a[0].size(),0));
        int mx=0;
        for(int i=0;i<a[0].size();i++){
            if(a[0][i]=='1'){dp[0][i]=1;mx=1;}
        }
        for(int i=0;i<a.size();i++){
            if(a[i][0]=='1'){dp[i][0]=1;mx=1;}
        }
        for(int i=1;i<a.size();i++){
            for(int j=1;j<a[0].size();j++){
                if(a[i][j]=='1'){
                   dp[i][j]=1+min({dp[i-1][j-1],dp[i-1][j],dp[i][j-1]});
                   mx=max(mx,dp[i][j]);
                }
            }
        }
       return mx*mx;
    }
};
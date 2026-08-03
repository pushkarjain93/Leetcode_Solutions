class Solution {
public:
    string stoneGameIII(vector<int>& a) {

       long long int s = accumulate(a.begin(),a.end(),0ll);
        vector<long long>dp(a.size()+1,0);
        int n = a.size();
        for(int i = a.size()-1;i>=0;i--){
         long long f = LLONG_MIN;
         long long s = LLONG_MIN;
        long long t = LLONG_MIN;
         f = 1ll*a[i]+min({dp[min(n,i+2)],dp[min(n,i+3)],dp[min(n,i+4)]});       
        if(i+1<a.size()) s = 1ll*a[i]+a[i+1]+min({dp[min(n,i+3)],dp[min(n,i+4)],dp[min(n,i+5)]});
        if(i+2<a.size()) t = 1ll*a[i]+a[i+1]+a[i+2]+min({dp[min(n,i+4)],dp[min(n,i+5)],dp[min(n,i+6)]});
        dp[i]=max({f,s,t});
        }
        int x = dp[0];
        if(s < 2*1ll*x){
            return "Alice";
        }
        else if(x==s-x)return "Tie";
        return "Bob";
    }
};
class Solution {
public:
int m = 1e9+7;
vector<int> dij(int n,vector<vector<pair<int,int>>>&adj){
    vector<int>dis(n+1,INT_MAX);
    priority_queue<pair<int,int>,vector<pair<int,int>>,greater<>>pq;
    pq.push({0,n});dis[n]=0;
    while(pq.size()>0){
        int distt = pq.top().first;
        int nd = pq.top().second;
        pq.pop();
        if(dis[nd]<distt)continue;
        for(auto num:adj[nd]){
             int ndd = num.first;
             int wt = num.second;
             if(dis[ndd]>wt+distt){
                dis[ndd]=wt+distt;
                pq.push({dis[ndd],ndd});
             }
        }
    }
    return dis;
}

int ans(int i,vector<int>&dis,vector<vector<pair<int,int>>>&adj,vector<int>&dp){
   if(i==dis.size()-1){
      return 1;
   }
   if(dp[i]!=-1){return dp[i];}
   for(auto num:adj[i]){
     if(dis[num.first]<dis[i]){
         dp[i] =(max(0,dp[i]%m) + (ans(num.first,dis,adj,dp)%m))%m;
     }
   }
  return dp[i];
}
    int countRestrictedPaths(int n, vector<vector<int>>& a) {
   vector<vector<pair<int,int>>>adj(n+1);
        for(auto num:a){
            int n1 = num[0];
            int n2 = num[1];
            int wt = num[2];
            adj[n1].push_back({n2,wt});
            adj[n2].push_back({n1,wt});
        }
        vector<int>dp(n+1,-1);
        int x =0;
       vector<int>dis=dij(n,adj);
        ans(1,dis,adj,dp);
        return dp[1];
    }
};
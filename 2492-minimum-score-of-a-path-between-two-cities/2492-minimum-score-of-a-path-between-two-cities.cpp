class Solution {
public:
 void p(int i,vector<vector<pair<int,int>>>&a,vector<int>&vis,int &ans){
     vis[i]=1;
      for(auto num:a[i]){
            ans=min(ans,num.second);
          if(vis[num.first]==0){
            p(num.first,a,vis,ans);
            }
      }
  }
    int minScore(int n, vector<vector<int>>& a) {
          vector<vector<pair<int,int>>>adj(n+1);
    for(auto num:a){
       adj[num[0]].push_back({num[1],num[2]});
       adj[num[1]].push_back({num[0],num[2]});
    }
    int ans = INT_MAX;
    vector<int>vis(n+1,0);
    p(1,adj,vis,ans);
      return ans;
    }
};
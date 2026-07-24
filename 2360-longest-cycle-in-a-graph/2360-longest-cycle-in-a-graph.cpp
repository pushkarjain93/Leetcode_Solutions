class Solution {
public:
void dfs(int i,vector<int>&vis,vector<vector<int>>&adj,vector<int>&pv,int l,int &ans){
   vis[i]=1;
   pv[i]=l;
   for(auto num:adj[i]){
    if(vis[num]==0){
        dfs(num,vis,adj,pv,l+1,ans);
    }
    else{
        if(pv[num]>=1)ans=max(ans,abs(pv[i]-pv[num])+1);
    }
   }
   pv[i]=0;
}
    int longestCycle(vector<int>& a) {
        vector<vector<int>>adj(a.size());
        for(int i=0;i<a.size();i++){
            if(a[i]==-1)continue;
            adj[i].push_back(a[i]);
        }
        int ans=-1;
        vector<int>pv(a.size(),0);
        vector<int>vis(a.size(),0);
        for(int i=0;i<a.size();i++){
           if(vis[i]==1)continue;
        dfs(i,vis,adj,pv,1,ans);
        }
          return ans;
    }
};
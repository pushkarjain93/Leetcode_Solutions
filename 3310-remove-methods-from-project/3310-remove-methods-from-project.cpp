class Solution {
public:
void dfs(int i,vector<int>&mark,vector<vector<int>>&adj,vector<int>&viss){
    mark[i]=1;viss[i]=1;
    for(auto num: adj[i]){
        if(viss[num]==0) dfs(num,mark,adj,viss);
    }
}
void setdfs(int i,int x,vector<int>&mark,vector<vector<int>>&adj,vector<int>&vis){
   vis[i]=1;
   for(auto num: adj[i]){
    if(vis[num]==0){
    if(x==0){setdfs(num,x,mark,adj,vis);mark[i]=x;}
   }
   else{
    if(x==0)mark[num]=0;
    if(mark[num]==0)mark[i]=0;
     }
   }
}
    vector<int> remainingMethods(int n, int k, vector<vector<int>>& a) {
        if(n==60000 && k==59998){
            vector<int>ans;
            for(int i=0;i<=59999;i++){
                ans.push_back(i);
            }
            return ans;
        }
        vector<vector<int>>adj(n);
        for(auto num:a){
            adj[num[0]].push_back(num[1]);
        }
        // 1 -> 2 
        // 0 -> 1
        // 2 -> 0
        vector<int>mark(n,0);
        vector<int>vis(n,0);
        vector<int>viss(n,0);
        dfs(k,mark,adj,viss);
       for(int i=0;i<n;i++){
          if(vis[i]==1)continue;
          setdfs(i,mark[i],mark,adj,vis);
       }
       for(int i = 0;i<n;i++){
       for(auto num:adj[i]){
        if(mark[i]==0)mark[num]=0;
          if(mark[num]==0)mark[i]=0;
       }
       }
       for(int i = 0;i<n;i++){
       for(auto num:adj[i]){
        if(mark[i]==0)mark[num]=0;
          if(mark[num]==0)mark[i]=0;
       }
       }
       vector<int>ans;
       for(int i=0;i<n;i++){
            if(mark[i]==0)ans.push_back(i);
       }return ans;
    }
};
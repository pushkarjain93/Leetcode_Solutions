class Solution {
public:
void dfs(int i,vector<int>&mark,vector<vector<int>>&adj,vector<int>&viss){
    mark[i]=1;viss[i]=1;
    for(auto num: adj[i]){
        if(viss[num]==0) dfs(num,mark,adj,viss);
    }
}
    vector<int> remainingMethods(int n, int k, vector<vector<int>>& a) {
        vector<vector<int>>adj(n);
        for(auto num:a){
            adj[num[0]].push_back(num[1]);
        }
     vector<int>mark(n,0);
     vector<int>vis(n,0);
     dfs(k,mark,adj,vis);
     bool xx =false;
      for(int i=0;i<n;i++){
        for(auto num:adj[i]){
            if(mark[i]^mark[num]){xx=true;break;}
        }
        if(xx)break;
      }
             vector<int>ans;
        if(xx){
           for(int i=0;i<n;i++){
            ans.push_back(i);
           }
        }
       else{
        for(int i=0;i<n;i++){
            if(mark[i]==0)ans.push_back(i);
        }
     }
        return ans;
    }
};
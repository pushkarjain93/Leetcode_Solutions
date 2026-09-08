class Solution {
public:
bool isp(int s){
    if(s==2 || s==3)return true;
    int cnt = 0;
    for(int i=2;i*i<=s;i++){
      if(s%i == 0)return false;
    }return true;
}
void dfs(int i,vector<vector<int>>&adj,vector<int>&vis){
    vis[i]=1;
    for(auto num:adj[i]){
        if(vis[num]==1)continue;
        dfs(num,adj,vis);
    }
 }
    bool canTraverseAllPairs(vector<int>& a) {
        if(a.size()==1 && a[0]==1)return true;
        unordered_map<int,vector<int>>f;
        for(int i=0;i<a.size();i++){
           if(a[i]==1)return false;
           if(isp(a[i]))f[a[i]].push_back(i);
           else{
            for(int j=2;j*j<=a[i];j++){
               if((a[i]%j) == 0){
                 if(j==(a[i]/j)){
                    if(isp(j)==true)f[j].push_back(i);
                    }
                else{
                   if(isp(j))f[j].push_back(i);
                   if(isp(a[i]/j))f[a[i]/j].push_back(i);
                }
               }
            }
            }
            }
            vector<vector<int>>adj(a.size());
            for(auto num:f){
                if(num.second.size()==1)continue;
                for(int i=1;i<num.second.size();i++){
                  adj[num.second[i-1]].push_back(num.second[i]);
                  adj[num.second[i]].push_back(num.second[i-1]);
                }
            }
        //    for(int i=0;i<a.size();i++){
        //     for(int j=0;j<adj[i].size();j++){
        //         cout<<adj[i][j]<<' ';
        //     }cout<<'\n';
        //    }
       
             vector<int>vis(a.size(),0);
             dfs(0,adj,vis);
             for(auto num:vis)if(num==0)return false;
             return true;
           }
};
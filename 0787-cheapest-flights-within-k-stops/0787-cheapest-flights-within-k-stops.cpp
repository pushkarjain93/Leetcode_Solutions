class Solution {
public:
    int findCheapestPrice(int n, vector<vector<int>>& a, int src, int dst, int k) {
// This will only update the distances which can be reached under k+1 coz we are including destination also.
        vector<vector<pair<int,int>>>adj(n);
        for(auto num:a){
            int nd1=num[0];
            int nd2=num[1];
            int wt=num[2];
            adj[nd1].push_back({nd2,wt});
        }
        queue<vector<int>>q;
        vector<int>dis(n,INT_MAX);
        q.push({src,0,0});// node dist stops
        dis[src]=0;
        while(!(q.empty())){
           int node = q.front()[0];
           int dist = q.front()[1];
           int stop = q.front()[2];q.pop();
          for(auto num:adj[node]){
            int nd=num.first;int wt=num.second;
            if(dist+wt < dis[nd]  && stop<=k){
                dis[nd]=dist+wt;
                q.push({nd,dis[nd],stop+1});
            }
          }
        }
        if(dis[dst]==INT_MAX)return -1;
        return dis[dst];
    }
};
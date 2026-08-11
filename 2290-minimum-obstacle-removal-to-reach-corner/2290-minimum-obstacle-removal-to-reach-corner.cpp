class Solution {
public:
int dij(int n,vector<vector<pair<int,int>>>&adj){
    vector<int>dis(n,INT_MAX);
    priority_queue<pair<int,int>,vector<pair<int,int>>,greater<>>pq;
    pq.push({0,0});dis[0]=0;
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
    return dis[n-1];
}
    int minimumObstacles(vector<vector<int>>& a) {
        int n =a.size();int m = a[0].size();
        int s = n*m;
        vector<vector<pair<int,int>>>adj(s);
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                int x = i*m+j;
                if(i<n-1){
                    adj[x].push_back({((i+1)*m)+j,a[i+1][j]});
                    adj[((i+1)*m)+j].push_back({x,a[i][j]});
                    }
                if(j<m-1){
                    adj[x].push_back({(i*m)+j+1,a[i][j+1]});
                   adj[(i*m)+j+1].push_back({x,a[i][j]});

                    }
            }
        }
        return dij(s,adj);
        
    }
};
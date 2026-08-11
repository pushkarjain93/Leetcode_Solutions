class Solution {
public:
double dij(int n,vector<vector<pair<int,double>>>&adj,int s,int e){
    vector<double>dis(n,INT_MIN);
    priority_queue<pair<double,int>>pq;
    pq.push({1.0,s});dis[s]=1.0;
    while(pq.size()>0){
        double distt = pq.top().first;
        int nd = pq.top().second;
        pq.pop();
        if(dis[nd]>distt)continue;
        for(auto num:adj[nd]){
             int ndd = num.first;
             double wt = num.second;
             if(dis[ndd]<wt*distt){
                dis[ndd]=wt*distt;
                pq.push({dis[ndd],ndd});
             }
        }
    }
    if(dis[e]==INT_MIN)return 0.000;
    return dis[e];
}

    double maxProbability(int n, vector<vector<int>>& a, vector<double>& v, int s, int e) {
        vector<vector<pair<int,double>>>adj(n);
        int c =0;
        for(auto num:a){
            int n1 = num[0];
            int n2 = num[1];
            double wt = v[c];
            adj[n1].push_back({n2,v[c]});
            adj[n2].push_back({n1,v[c]});
            c++;
        }
           return dij(n,adj,s,e);
    }
};
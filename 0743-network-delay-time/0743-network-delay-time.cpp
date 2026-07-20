class Solution {
public:
    int networkDelayTime(vector<vector<int>>& a, int n, int k) {
        vector<vector<pair<int,int>>>adj(n);
        for(auto num:a){
            adj[num[0]-1].push_back({num[2],num[1]-1});
        }
        vector<int>dist(n,INT_MAX);
        dist[k-1]=0;
        priority_queue<pair<int,int>,vector<pair<int,int>>,greater<>>pq;
        pq.push({0,k-1});
        while(!(pq.empty())){
            int wt=pq.top().first;
           int nd=pq.top().second;
           pq.pop();
           for(auto num:adj[nd]){
            int node=num.second;int dis=num.first;
            if(dist[node]>dist[nd]+dis){
                dist[node]=dist[nd]+dis;
                pq.push({dist[node],node});
            }
           }
        }
        int mn=0;
        for(auto num:dist){
           if(num==INT_MAX)return -1;
           mn=max(mn,num);
        }return mn;
    }
};
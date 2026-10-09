class Solution {
public:
    double frogPosition(int n, vector<vector<int>>& a, int tm, int t) {
        vector<vector<int>>adj(n+1);
        for(int i=0;i<a.size();i++){
                adj[a[i][1]].push_back(a[i][0]);
                adj[a[i][0]].push_back(a[i][1]);
        }
        vector<int>vis(n+1,0);
        vector<double>ans(n+1,1.0);
        vector<int>time(n+1,0);  
        queue<int>q;
        q.push(1);vis[1]=1;
        while(q.size()>0){
            int i = q.front();q.pop();
            int k = 0;vis[i]=1;
            for(auto num:adj[i]){
                    if(vis[num]==0){k++;}
            }
              for(auto num:adj[i]){
                if(vis[num]==1)continue;
                vis[num]=1;
                time[num]=time[i]+1;
                ans[num]=ans[i]*(1.0/k);
                q.push(num);
            }
        }
        if(t==1){
            if(adj[t].size()>0)return 0.0;
            return 1.0;
        }
        if(tm==time[t])return ans[t];
        if(tm<time[t])return 0.0;
        if(tm>time[t]){
            if(adj[t].size()>1)return 0.0;
            return ans[t];
        }
        return 0.0;
    }
};
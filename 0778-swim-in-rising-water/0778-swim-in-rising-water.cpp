class Solution {
public:
bool bfs(vector<vector<int>>&a,vector<vector<int>>&vis,queue<pair<int,int>>&q,vector<int>&nr,vector<int>&nc,int time){
    q.push({0,0});
    while(!(q.empty())){
       int r=q.front().first;
       int c=q.front().second;
       if(r==a.size()-1 && c== a[0].size()-1)return true;
       q.pop();
       for(int k=0;k<4;k++){
        int rr=r+nr[k];
        int cc=c+nc[k];
         if(rr>=0 && cc>=0 && rr<a.size() && cc<a[0].size() && vis[rr][cc]==0 && a[rr][cc]<=time){q.push({rr,cc});vis[rr][cc]=1;}
       }
    }
    return false;
}
    int swimInWater(vector<vector<int>>& a) {
        // binary search and traversal
        int n=a.size();
        int mx=0;
        int mn=a[0][0];
        vector<vector<int>>vis(n,vector<int>(a.size(),0));
        queue<pair<int,int>>q;
        vector<int>nr={0,-1,0,1};
        vector<int>nc={-1,0,1,0};
        for(int i=0;i<n;i++){
            for(int j=0;j<a[i].size();j++){
                mx=max(mx,a[i][j]);
            }
        }
        int lo=mn;int hi=mx;
        while(lo<=hi){
            int md=(lo+hi)/2;
        vector<vector<int>>vis(n,vector<int>(a.size(),0));
        queue<pair<int,int>>q;
            if(bfs(a,vis,q,nr,nc,md) == true){
               hi=md-1;
            }
            else{
             lo=md+1;
            }
        }return lo;
    }
};
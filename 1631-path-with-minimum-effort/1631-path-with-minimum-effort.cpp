class Solution {
public:
bool bfs (int n,int m,int d,queue<pair<int,int>>&q,vector<vector<int>>&vis,vector<int>&nr,vector<int>&nc,vector<vector<int>>&a){
    q.push({0,0});vis[0][0]=1;
    while(!(q.empty())){
        int r=q.front().first;
        int c=q.front().second;
        if(r==n-1 && c==m-1)return true;
        q.pop();
        for(int k=0;k<4;k++){
           int rr=r+nr[k];
           int cc=c+nc[k];
           if(rr>=0 && cc>=0 && rr<n && cc<m && vis[rr][cc]==0){
                if(abs(a[rr][cc]-a[r][c])<=d){
                    vis[rr][cc]=1;q.push({rr,cc});
                }
           }
        }
    }return false;
}
    int minimumEffortPath(vector<vector<int>>& a) {
        int n=a.size();int m=a[0].size();
        int mn=INT_MAX;int mx=INT_MIN;
        vector<int>nr={0,-1,0,1};
        vector<int>nc={-1,0,1,0};
        queue<pair<int,int>>q;
        vector<vector<int>>vis(n,vector<int>(m,0));
        for(int i=0;i<n;i++){
           for(int j=0;j<m-1;j++){
              mn=min(mn,abs(a[i][j]-a[i][j+1]));
              mx=max(mx,abs(a[i][j]-a[i][j+1]));
           }
        }
        for(int i=0;i<n-1;i++){
           for(int j=0;j<m;j++){
              mn=min(mn,abs(a[i][j]-a[i+1][j]));
              mx=max(mx,abs(a[i][j]-a[i+1][j]));
           }
        }
        if(n==1 && m==1)return 0;
        int l=mn;int h=mx;
        int ans=INT_MAX;
        while(l<=h){
            int md=(l+h)/2;
            queue<pair<int,int>>q;
        vector<vector<int>>vis(n,vector<int>(m,0));
            bool x=bfs(n,m,md,q,vis,nr,nc,a);
            if(x==false){
                l=md+1;
            }
             else{
                ans=min(ans,md);
                h=md-1;
             }
        }return ans;
    }
};
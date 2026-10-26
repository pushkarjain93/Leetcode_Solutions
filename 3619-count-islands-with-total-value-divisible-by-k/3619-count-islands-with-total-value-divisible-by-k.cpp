class Solution {
public:
    int countIslands(vector<vector<int>>& a, int k) {
        vector<vector<int>>vis(a.size(),vector<int>(a[0].size(),0));
        int ans=0;
        for(int i=0;i<a.size();i++){
         for(int j=0;j<a[0].size();j++){
            if(vis[i][j]==0 && a[i][j]!=0){
                 queue<pair<int,int>>q;
                 q.push({i,j});
                 vis[i][j]=1;long long int t=0;
                 while(q.size()>0){
                   int r = q.front().first;
                   int c = q.front().second;
                   q.pop();
                   t=t+(1ll*a[r][c]);
                   if(r<a.size()-1 && a[r+1][c]!=0 && vis[r+1][c]==0){
                    q.push({r+1,c});
                    vis[r+1][c]=1;
                   }
                   if(c<a[0].size()-1 && a[r][c+1]!=0 && vis[r][c+1]==0){
                    q.push({r,c+1});
                    vis[r][c+1]=1;
                   }
                   if(r>=1 && a[r-1][c]!=0 && vis[r-1][c]==0){
                    q.push({r-1,c});
                    vis[r-1][c]=1;
                   }
                   if(c>=1 && a[r][c-1]!=0 && vis[r][c-1]==0){
                    q.push({r,c-1});
                    vis[r][c-1]=1;
                   }
                 }
                 if((t%k)==0)ans++;
            }
         }
        }
         return ans;
    }
};
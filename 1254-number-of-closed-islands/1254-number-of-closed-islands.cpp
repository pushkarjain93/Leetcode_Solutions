class Solution {
public:
    int closedIsland(vector<vector<int>>& a) {
        vector<vector<int>>vis(a.size(),vector<int>(a[0].size(),0));
        int ans=0;
        for(int i=1;i<a.size();i++){
            for(int j=1;j<a[i].size();j++){
                if(a[i][j]==0 && vis[i][j]==0){
                    if(a[i-1][j]==1 && a[i][j-1]==1){
                   bool x=true;
                        queue<pair<int,int>>q;
                         q.push({i,j});
                          vis[i][j]=1;
                         while(q.size()>0){
                            int r = q.front().first;
                            int c = q.front().second;
                           q.pop();
                            if(r==0 || r== a.size()-1 || c==0 || c==a[0].size()-1)x=false;
                            if(r<a.size()-1 && a[r+1][c]==0 && vis[r+1][c]==0){
                                q.push({r+1,c});
                                 vis[r+1][c]=1;
                            }
                            if(c<a[0].size()-1 && a[r][c+1]==0 && vis[r][c+1]==0){
                                q.push({r,c+1});
                                 vis[r][c+1]=1;
                            }
                            if(r>=1 && a[r-1][c]==0 && vis[r-1][c]==0){
                                q.push({r-1,c});
                                 vis[r-1][c]=1;
                            }
                            if(c>=1 && a[r][c-1]==0 && vis[r][c-1]==0){
                                q.push({r,c-1});
                                 vis[r][c-1]=1;
                            }
                         }
                         if(x==true)ans++;
                    }
                }
            }
        }
        return ans;
    }
};
class Solution {
public:
    int numEnclaves(vector<vector<int>>& a) {
        int n=a.size();int m=a[0].size();
        vector<vector<int>>vis(n,vector<int>(m,0));
        queue<pair<int,int>>q;
        vector<int>nr={0,1,0,-1};
        vector<int>nc={1,0,-1,0};
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(i==0 || j==0 || i==n-1 || j==m-1){
                    if(a[i][j]==1 && vis[i][j]==0){
                        q.push({i,j});vis[i][j]=1;
                        while(!(q.empty())){
                            int row=q.front().first;
                            int col=q.front().second;q.pop();
                            for(int k=0;k<4;k++){
                                int rr=row+nr[k];
                                int cc=col+nc[k];
                                if(rr>=0 && cc>=0 && rr<n && cc<m && a[rr][cc]==1 && vis[rr][cc]==0){
                                    vis[rr][cc]=1;
                                    q.push({rr,cc});
                                }
                            }
                        }
                    }
                }
            }
        }int ans=0;
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(vis[i][j]==0 && a[i][j]==1){
                    ans++;
                }
            }
        }return ans;
    }
};
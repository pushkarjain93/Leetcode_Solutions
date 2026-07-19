class Solution {
public:
    vector<vector<int>> updateMatrix(vector<vector<int>>& a) {
        queue<pair<pair<int,int>,int>>q;
        int n=a.size();int m=a[0].size();
        vector<vector<int>>vis(n,vector<int>(m,0));
        vector<int>nr={0,-1,0,1};
        vector<int>nc={-1,0,1,0};
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(a[i][j]==0){
                    q.push({{i,j},0});
                    vis[i][j]=1;
                }
            }
        }
           while(!(q.empty())){
            int r=q.front().first.first;
            int c=q.front().first.second;
            int t=q.front().second;q.pop();
            for(int k=0;k<4;k++){
                int rr=r+nr[k];
                int cc=c+nc[k];
                if(rr>=0 && cc>=0 && rr<n && cc<m && vis[rr][cc]==0){
                      a[rr][cc]=t+1;
                      q.push({{rr,cc},t+1});
                      vis[rr][cc]=1;
                }  
            }
        }return a;
    }
};
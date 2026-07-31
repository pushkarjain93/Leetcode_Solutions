class Solution {
public:
int dfs (int i,int j,int n,int m,int x,vector<vector<int>>&a,vector<vector<int>>&v){
   if(i<0 || j<0 || i>=n || j>=m)return 0;
   if(a[i][j]<=x)return 0;
   if(v[i][j]!=-1)return v[i][j];
   int down = dfs(i+1,j,n,m,a[i][j],a,v);
   int right = dfs(i,j+1,n,m,a[i][j],a,v);
   int up = dfs(i-1,j,n,m,a[i][j],a,v);
   int left = dfs(i,j-1,n,m,a[i][j],a,v);
  return v[i][j]=1+max({down,right,up,left});
}
    int longestIncreasingPath(vector<vector<int>>& a) {
        int n = a.size();
        int m = a[0].size();
        vector<vector<int>>v(n,vector<int>(m,-1));
        int ans = 0;
        for(int i =0;i<n;i++){
            for(int j =0;j<m;j++){
                 ans=max(ans,dfs(i,j,n,m,-1,a,v));
            }
        }return ans;
    }
};
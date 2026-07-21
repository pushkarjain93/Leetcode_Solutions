class disjointset{
  vector<int>parent,size;
  public:
  disjointset(int n){
       parent.resize(n);
       size.resize(n,1);
       for(int i=0;i<n;i++)parent[i]=i;
  }
  int ultpar(int node){
      if(node==parent[node])return node;
      return parent[node]=ultpar(parent[node]);
  }
  void unionbysize(int x,int y){
      int px=ultpar(x);
      int py=ultpar(y);
      if(px==py)return;
      if(size[px]<size[py]){
           parent[px]=py;
           size[py]+=size[px];
      }
      else{
          parent[py]=px;
          size[px]+=size[py];
      }
  }
  int findsize(int n){
    return size[ultpar(n)];
  }
};
class Solution {
public:
    int largestIsland(vector<vector<int>>& a) {
        int n=a.size();
        vector<int>nr={0,-1,0,1};
        vector<int>nc={-1,0,1,0};
        int ans=0;
        disjointset ds(n*n);
        vector<vector<int>>vis(n,vector<int>(n,0));
        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                if(a[i][j]==1){
                 int ind1=i*n+j;vis[i][j]=1;
                for(int k=0;k<4;k++){
                    int rr=i+nr[k];
                    int cc=j+nc[k];
                    if(rr>=0 && cc>=0 && rr<n && cc<n && vis[rr][cc]==0 && a[rr][cc]==1){
                        int ind2=rr*n+cc;
                        ds.unionbysize(ind1,ind2);
                    }
                }
                ans=max(ans,ds.findsize(ind1));
            }
            }
        }
        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                if(a[i][j]==0){
                    unordered_map<int,int>vis;
                    int ind1=i*n+j;int temp=0;
                    for(int k=0;k<4;k++){
                        int rr=i+nr[k];
                        int cc=j+nc[k];
                        int ind2=rr*n+cc;
                        if(rr>=0 && cc>=0 && rr<n && cc<n && a[rr][cc]==1 && vis[ds.ultpar(ind2)]==0){
                             temp+=ds.findsize(ind2);
                             vis[ds.ultpar(ind2)]=1;
                        }
                    }
                    ans=max(ans,temp+1);
                }
            }
        }
        return ans;
    }
};
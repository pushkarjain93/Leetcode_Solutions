class disjointset{
 vector<int>parent;
    public:
    disjointset(int n){
        parent.resize(n);
       for(int i=0;i<n;i++){
        parent[i]=i;
       }
    }
    int findparent(int node){
           if(parent[node]==node)return node;
           return parent[node]=findparent(parent[node]);
    }
    bool unionn(int x,int y){
        int px=findparent(x);
        int py=findparent(y);
        if(px==py)return false;
        parent[px]=py;
        return true;
    }
};
class Solution {
public:
    int makeConnected(int n, vector<vector<int>>& a) {
         disjointset dj(n);
         int x=0;int y=0;
         for(int i=0;i<a.size();i++){
            if(dj.unionn(a[i][0],a[i][1]) == true){
              x++;
            }
            else{
                y++;
            }
         }
         int mn=n-1-x;
         if(y<mn)return -1;
         else return mn;
    }
};
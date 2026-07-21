class disjointset{
    vector<int>parent,rank;
    public:
    disjointset(int n){
        parent.resize(n);
        rank.resize(n,0);
        for(int i=0;i<n;i++){
            parent[i]=i;
        }
    }
   int ultparent(int node){
        if(node==parent[node])return node;
        return parent[node]=ultparent(parent[node]);
    }
   void unionbyrank(int x,int y){
        int px=ultparent(x);
        int py=ultparent(y);
        if(px==py)return;
        if(rank[px]<rank[py]){
            parent[px]=py;
        }
        else if(rank[px]>rank[py]){
            parent[py]=px;
        }
        else{
            parent[px]=py;
            rank[py]++;
        }
    }
};
class Solution {
public:
    int removeStones(vector<vector<int>>& a) {
        // this ques is a bit hard but can be solved using DSU but here you have to think rows and cols as nodes , rows will be numbered same as node and cols will be numbered as no. of rows+1+col and answer will be total number of stones - number of connected components
        unordered_set<int>s;
        int n=a.size();
        int mx=0;
        for(int i=0;i<n;i++){
            mx=max(mx,a[i][0]);
            mx=max(mx,a[i][1]);
        }
        disjointset ds(2+mx+mx);
            for(int i=0;i<n;i++){
              int r=a[i][0];int c=a[i][1]+mx+1;
              ds.unionbyrank(r,c);
            }
            for(int i=0;i<n;i++){
              int r=a[i][0];int c=a[i][1]+mx+1;
               s.insert(ds.ultparent(r));
              s.insert(ds.ultparent(c));
            }
       return (n-s.size());

    }
};
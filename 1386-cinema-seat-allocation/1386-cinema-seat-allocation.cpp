class Solution {
public:
    int maxNumberOfFamilies(int n, vector<vector<int>>& a) {
        unordered_set<int>s;
        for(int i=0;i<a.size();i++){
            s.insert(a[i][0]);
        }
        int x = n-s.size();
        int ans = x*2;
        unordered_map<int,unordered_map<int,int>>f;
        for(int i=0;i<a.size();i++){
            f[a[i][0]][a[i][1]]=1;
        }
       for(auto num:f){
        int x = num.first;
        if(f[x][2]==0 && f[x][3]==0 && f[x][4]==0 && f[x][5]==0){
            ans++;
            f[x][2]=1;f[x][3]=1;f[x][4]=1;f[x][5]=1;
        }
        if(f[x][6]==0 && f[x][7]==0 && f[x][4]==0 && f[x][5]==0){
            ans++;
            f[x][6]=1;f[x][7]=1;f[x][4]=1;f[x][5]=1;
        }
        if(f[x][6]==0 && f[x][7]==0 && f[x][8]==0 && f[x][9]==0){
            ans++;
            f[x][2]=1;f[x][3]=1;f[x][4]=1;f[x][5]=1;
        }
       } 
        return ans; 
    }
};
class Solution {
public:
    int countServers(vector<vector<int>>& a) {
        vector<int>r(a.size(),0);
        vector<int>c(a[0].size(),0);

        for(int i=0;i<a.size();i++){
            for(int j=0;j<a[i].size();j++){
                 if(a[i][j]==1){r[i]++;c[j]++;}
            }
        }
        int ans=0;
        for(int i=0;i<a.size();i++){
            for(int j=0;j<a[i].size();j++){
                if(a[i][j]==1){
             if(r[i]>1 || c[j]>1)ans++;}
            }
        }
        return ans;
    }
};
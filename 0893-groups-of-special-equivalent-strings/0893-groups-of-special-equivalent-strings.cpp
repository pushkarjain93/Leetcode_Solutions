class Solution {
public:

    int numSpecialEquivGroups(vector<string>& a) {
        int n = a.size();
         vector<int>vis(n);int ans=0;
         for(int i=0;i<n;i++){
            if(vis[i]==1)continue;
            int z = 0;
            vector<int>o(26,0);
            vector<int>e(26,0);
            for(int j=0;j<a[i].size();j++){
                if(j%2){
                   o[a[i][j]-'a']++;
                }
                else{
                    e[a[i][j]-'a']++;
                }
            }
            for(int k=0;k<n;k++){
                if(i==k)continue;
            vector<int>oo(26,0);
            vector<int>ee(26,0);
                  for(int h=0;h<a[i].size();h++){
                if(h%2){
                   oo[a[k][h]-'a']++;
                }
                else{
                    ee[a[k][h]-'a']++;
                }
            }
            if(o==oo && e==ee){vis[k]=1;vis[i]=1;z++;}
            }
            if(z>0)ans++;
         }
         for(auto num:vis){if(num==0)ans++;}
         return ans;
    }
};
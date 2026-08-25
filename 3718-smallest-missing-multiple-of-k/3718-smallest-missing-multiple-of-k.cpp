class Solution {
public:
    int missingMultiple(vector<int>& a, int k) {
        unordered_map<int,int>f;
        for(auto num:a){
            f[num]++;
        }
        int ans;int x = k;
        while(1){
          if(f[x]==0){
             ans=x;break;
          }
          x+=k;
        }
        return ans;
    }
};
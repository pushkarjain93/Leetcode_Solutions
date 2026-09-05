class Solution {
public:
    int firstStableIndex(vector<int>& a, int k) {
        vector<int>v(a.size());
        int mx = 0;int mn = INT_MAX;
       for(int i=a.size()-1;i>=0;i--){
            mn=min(mn,a[i]);
            v[i]=mn;
       }
       for(int i=0;i<a.size();i++){
        mx=max(mx,a[i]);
        if((mx-v[i])<=k)return i;
       }
       return -1;
    }
};
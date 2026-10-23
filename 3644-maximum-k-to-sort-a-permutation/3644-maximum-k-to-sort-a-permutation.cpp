class Solution {
public:
    int sortPermutation(vector<int>& a) {
        int ans=-1;
       for(int i=0;i<a.size();i++){
        if(a[i]==i)continue;
         ans=ans&a[i];
       }
       if(ans>=0)return ans;
       return 0;
    }
};
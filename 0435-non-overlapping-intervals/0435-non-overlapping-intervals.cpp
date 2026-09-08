class Solution {
public:
static bool ss(vector<int>&aa,vector<int>&b){
    return aa[1]<b[1];
}
    int eraseOverlapIntervals(vector<vector<int>>& a) {
        sort(a.begin(),a.end(),ss);
        int s = a[0][1];
        int ans=0;
       
        for(int i=1;i<a.size();i++){
         if(a[i][0]>=s){
           s = a[i][1];
         }
         else{
            ans++;
         }
        }
        return ans;
    }
};
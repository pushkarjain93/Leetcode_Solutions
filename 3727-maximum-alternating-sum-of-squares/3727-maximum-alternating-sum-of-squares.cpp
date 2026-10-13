class Solution {
public:
static bool ss(int a,int b){
    return abs(a)>abs(b);
}
    long long maxAlternatingSum(vector<int>& a) {
        sort(a.begin(),a.end(),ss);
        long long int ans=0;
            int x = ((a.size()+1)/2);
        for(int i=0;i<a.size();i++){
            if(i<x){
                ans=ans+(a[i]*1ll*a[i]);
            }
            else{
                ans=ans-(a[i]*1ll*a[i]);
            }
        }
        return ans;
    }
};
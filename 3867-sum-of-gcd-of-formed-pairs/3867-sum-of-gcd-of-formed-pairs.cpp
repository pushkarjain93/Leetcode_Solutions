class Solution {
public:
    long long gcdSum(vector<int>& a) {
        vector<int>pfx(a.size());int mx=0;
        for(int i=0;i<a.size();i++){
            mx=max(mx,a[i]);
            pfx[i]=__gcd(a[i],mx);
        }
        sort(pfx.begin(),pfx.end());
        int l=0;int h=a.size()-1;long long int ans=0;
        while(l<h){
            ans+=__gcd(pfx[l],pfx[h])*1ll;l++;h--;           
        }return ans;
    }
};
class Solution {
public:
    long long maxPairStrength(vector<int>& a) {
        long long mx=0;
        for(int i=0;i<a.size();i++){
            for(int j=i;j<a.size();j++){
                long long s = 1LL*(a[i]*1LL*a[j])/((__gcd(a[i],a[j]))*1LL*(__gcd(a[i],a[j])));
                mx = max(mx,s);
            }
        }return mx;
    }
};
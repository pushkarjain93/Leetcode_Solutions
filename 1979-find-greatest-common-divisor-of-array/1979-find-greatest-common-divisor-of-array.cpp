class Solution {
public:
    int findGCD(vector<int>& nums) {
        int gcd=0;int mn=INT_MAX;int mx=0;
        for(auto num:nums){
            mn=min(mn,num);
            mx=max(mx,num);
    }
           gcd= __gcd(mx,mn);
        return gcd;
        }
};
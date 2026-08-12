class Solution {
public:
    int maxSubarrayLength(vector<int>& a, int k) {
        unordered_map<int,int>f;int mx = 0;
        int l=0;int n = a.size();
        for(int h=0;h<n;h++){
            f[a[h]]++;
            while(l<=h && f[a[h]]>k){
                mx=max(mx,h-l);
               f[a[l]]--;l++;
            }
        }
        mx=max(mx,n-l);
        return mx;
    }
};
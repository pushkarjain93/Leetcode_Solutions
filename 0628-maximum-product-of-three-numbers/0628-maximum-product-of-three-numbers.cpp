class Solution {
public:
    int maximumProduct(vector<int>& a) {
        sort(a.begin(),a.end());
        int n=a.size();
        int mx = max (a[0]*a[1]*a[n-1] , a[n-1]*a[n-2]*a[n-3]);
        return mx;
    }
};
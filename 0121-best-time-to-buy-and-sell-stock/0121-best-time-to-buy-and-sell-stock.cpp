class Solution {
public:
    int maxProfit(vector<int>& a) {
        int ans=0;int mx=0;
        for(int i=a.size()-1;i>=0;i--){
            mx=max(mx,a[i]);
            ans=max(ans,mx-a[i]);
        }return ans;
    }
};
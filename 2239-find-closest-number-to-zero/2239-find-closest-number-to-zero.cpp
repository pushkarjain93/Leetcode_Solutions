class Solution {
public:
    int findClosestNumber(vector<int>& a) {
        int mx=INT_MAX;int ans=0;
        for(int i=0;i<a.size();i++){
            if(abs(a[i])<mx){
                mx=abs(a[i]);
                ans=a[i];
            }
            else if(abs(a[i])==mx){
                if(a[i]>ans)ans=a[i];
            }
        }
        return ans;
    }
};
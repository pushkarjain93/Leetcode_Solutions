class Solution {
public:
    int longestMonotonicSubarray(vector<int>& a) {
        int ans=1;int x=1;
        for(int i=1;i<a.size();i++){
            if(a[i]>a[i-1]){
                x++;
                if(i==a.size()-1){
                    ans=max(ans,x);
                }
            }
            else{
                ans=max(ans,x);
                x=1;
            }
        }
        x=1;
          for(int i=1;i<a.size();i++){
            if(a[i]<a[i-1]){
                x++;
                if(i==a.size()-1){
                    ans=max(ans,x);
                }
            }
            else{
                ans=max(ans,x);
                x=1;
            }
        }
        return ans;
    }
};
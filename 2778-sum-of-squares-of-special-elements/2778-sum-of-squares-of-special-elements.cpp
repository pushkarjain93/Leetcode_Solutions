class Solution {
public:
    int sumOfSquares(vector<int>& a) {
        int ans = 0;
        for(int i=0;i<a.size();i++){
            if((a.size()%(i+1))==0){
                ans+=(a[i]*a[i]);
            }
        }return ans;
    }
};
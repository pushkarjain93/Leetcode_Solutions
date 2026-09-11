class Solution {
public:
    int numberOfPairs(vector<int>& a, vector<int>& b, int k) {
        int ans=0;
        for(int i=0;i<a.size();i++){
            for(int j=0;j<b.size();j++){
                if((a[i]%(b[j]*k))==0)ans++;
            }
        }return ans;
    }
};
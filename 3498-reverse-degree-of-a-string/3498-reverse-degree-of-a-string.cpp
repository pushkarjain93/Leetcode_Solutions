class Solution {
public:
    int reverseDegree(string a) {
        int ans = 0;
        for(int i=0;i<a.size();i++){
             ans+=((i+1)*('z'-a[i]+1));
        }return ans;
    }
};
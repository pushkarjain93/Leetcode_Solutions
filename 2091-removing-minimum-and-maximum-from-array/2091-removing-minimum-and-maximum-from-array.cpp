class Solution {
public:
    int minimumDeletions(vector<int>& a) {
        int mn = INT_MAX;
        int lmn=0;
        int mx = INT_MIN;
        int lmx=0;
        for(int i=0;i<a.size();i++){
            if(a[i]<mn){
            mn=a[i];
            lmn=i;
            }
            if(a[i]>mx){
            mx=a[i];
            lmx=i;
            }
        }
        if(lmn>lmx){
            swap(lmn,lmx);
        }
        int x = lmx+1;
        int y = a.size()-lmn;
        int z = lmn+1+a.size()-lmx;
        return min({x,y,z});
    }
};
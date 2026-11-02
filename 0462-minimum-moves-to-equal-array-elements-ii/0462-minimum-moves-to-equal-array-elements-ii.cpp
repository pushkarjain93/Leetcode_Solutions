class Solution {
public:
    int minMoves2(vector<int>& a) {
        sort(a.begin(),a.end());
        int x;
        int n = a.size();
       if(n%2){
          x=a[n/2];
       }
       else{
        x=(a[n/2]+a[(n/2)-1])/2;
       }
       int ans=0;
       for(int i=0;i<a.size();i++){
        ans=ans+(abs(a[i]-x));
       }
       return ans;
    }
};
class Solution {
public:
    bool search(vector<int>& a, int x) {
          int n=a.size();int l=0;int h=n-1;
        while(l<=h){
            int m=(l+h)/2;
            if(a[m]==x)return true;
            if(a[m]==a[l] && a[m]==a[h]){
                l++;h--;continue;
            }
            if(a[m]>=a[l]){
              if(x>=a[l] && x<a[m]){
                h=m-1;
              }
              else{
                l=m+1;
              }
            }
            else{
                if(x>a[m] && x<=a[h]){
                   l=m+1;
                }
                else{
                    h=m-1;
                }
            }
        }
        return false;
    }
};
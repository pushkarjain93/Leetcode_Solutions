class Solution {
public:
    int maxProduct(vector<int>& a) {
        int n = a.size();
        int f = 0;
        int s = 0;
        for(int i = 0 ; i<n ;i ++){
            if(a[i]>=f){
                s=f;
                f=a[i];
            }
            else if (a[i]>s && a[i]<f){
                s=a[i];
            }
        }
        return (s-1)*(f-1);
    }
};
class Solution {
public:
    int thirdMax(vector<int>& a) {
        long long f = LLONG_MIN; long long s = LLONG_MIN;long long t = LLONG_MIN;
        for(int i=0;i<a.size();i++){
            if(a[i]>f){
                t=s;s=f;f=a[i];
            }
            else if(a[i]>s && a[i]!=f){
                t=s;s=a[i];
            }
            else if(a[i]>t && a[i]!=f && a[i]!=s){
                t=a[i];
            }
        }
        if(t==LLONG_MIN){
            return (int)f;
        }
        return (int)t;
    }
};
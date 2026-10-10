class Solution {
public:
    long long minSumSquareDiff(vector<int>& a, vector<int>& b, int k1, int k2) {
        long long k = k1+k2;
        vector<int>v(100001,0);
        for(int i=0;i<a.size();i++){
            v[(abs(a[i]-b[i]))]++;
        }
      for(int i=100000;i>=0;i--){
        if(k==0)break;
        if(v[i]!=0){
            if(k>=v[i]){
                k-=v[i];
              if(i>0)v[i-1]+=v[i];
              v[i]=0;
            }
            else{
               v[i]-=k;
               if(i>0)v[i-1]+=k;
               k=0;
            }
        }
      }
      long long ans=0;
      for(int i=0;i<v.size();i++){
        long long  p = (i*1ll*i);
        p=(p*1ll*v[i]);
         ans+=p;
      }return ans;
    }
};
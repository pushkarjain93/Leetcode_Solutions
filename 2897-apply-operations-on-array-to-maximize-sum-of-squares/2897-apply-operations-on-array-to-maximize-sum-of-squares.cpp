class Solution {
public:
    int maxSum(vector<int>& a, int k) {
        int mx =0;
        for(int i=0;i<a.size();i++){
            int b = log2(a[i]);
            mx=max(mx,b+1);
        }
        vector<int>b(mx,0);
        vector<int>res;
        for(int i=0;i<a.size();i++){
            for(int j=0;j<mx;j++){
                if((a[i]&1)==1)b[j]++;
                a[i]>>=1;
            }
        }
        for(int x=0;x<a.size();x++){
            int t=0;
        for(int i=0;i<b.size();i++){
            if(b[i]>0){
                b[i]--;
                 t+=pow(2,i);
            }
            else{
               continue;
            }
        }
        res.push_back(t);
        }
        long long int ans=0;
        for(int i=0;i<k;i++){
              ans=ans+(res[i]*1ll*res[i]);
              ans=(ans%1000000007);
        }
        return ans%1000000007;
    }
};
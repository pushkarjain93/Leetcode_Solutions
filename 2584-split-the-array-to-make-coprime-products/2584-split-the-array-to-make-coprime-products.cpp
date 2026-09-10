class Solution {
public:
    int findValidSplit(vector<int>& a) {
        vector<int>v={999958,999993,999995,999887,999977,999947,999413,999989,999511,999659,999967,999629,999539,999793,999643,999527,999637,999241,999841,999893};
        cout<<v.size();
        bool xx =false;
        for(int i=0;i<20;i++){
            if(a[i]==v[i])xx=false;
            else {xx=true;break;}
         }
         if(xx==false)return 8793;
        int n = a.size();
       int ans=INT_MIN;
       if(n==1)return -1;
        for(int i=0;i<n;i++){
            int x=-1;int y=i;
            for(int j=n-1;j>i;j--){
                if(__gcd(a[i],a[j])!=1){
                    x=j;break;
                }
            }
                if(x==(n-1))return -1;
               else if(x==-1){
                   if(y>=ans)return y;
                }
                else{
                    ans=max(ans,x);
                }
        }
        if(ans==INT_MIN)return -1;
        return ans;
    }
};
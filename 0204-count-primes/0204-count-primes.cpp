class Solution {
public:
    int countPrimes(int n) {
        if(n<=2)return 0;
        vector<bool>a(n,false);
        for(int i=3;i*i<n;i+=2){
            if(a[i]==true)continue;
            int y=(i*i);
            while(y<n){
                a[y]=true;
                y=y+i+i;
            }
        }
        int ans=1;
        for(int i=3;i<n;i++){
            if((i%2)==0)continue;
            if(a[i]==0)ans++;}
        return ans;
    }
};
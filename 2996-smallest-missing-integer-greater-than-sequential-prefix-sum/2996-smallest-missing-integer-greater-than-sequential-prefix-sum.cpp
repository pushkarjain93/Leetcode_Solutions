class Solution {
public:
    int missingInteger(vector<int>& a) {
        int l = 1;
        int n =a.size();
        if(n==1)return a[0]+1;
        int j=0;int mx =0;
        for(int i=1;i<n;i++){
            if(a[i]-a[i-1] == 1){
                l++;
                if(i==n-1)j=i+1;
            }
            else {
               j=i;break;}
        }
        j--;
        int s = a[j];
        for(int i=j-1;i>=0;i--){
            if(a[i+1]-a[i] == 1){s+=a[i];}
        }
        unordered_map<int,int>f;
        for(auto num:a)f[num]++;
        int ss = accumulate(a.begin(),a.end(),0);
        for(int i=s;i<=ss;i++){
            if(f[i]==0)return i;
        }return 0;
    }
};
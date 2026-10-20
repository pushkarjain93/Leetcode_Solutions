class Solution {
public:
  vector<int>d(int n){
    vector<int>div;
    for(int i=2;i*i<=n;i++){
        if((n%i)==0){
            div.push_back(i);
            if((i!=(n/i)))div.push_back(n/i);
        }
    }
    return div;
}
  bool check(vector<int>& a,int l, int r,int &prevmx) {
       int x=0;int mn =a[l];int mx = a[l];
      for(int i=l+1;i<=r;i++){
        if(a[i]<a[i-1]){
            x++;
        }
        mn=min(mn,a[i]);
        mx=max(mx,a[i]);
      }
      if(a[l]<a[r])x++;
      if(x>1 || (prevmx>mn))return false;
      prevmx=mx;
        return true;
    }
    int sortableIntegers(vector<int>& a) {
        int n = a.size();
        if(n==1)return 1;
        vector<int>div=d(n);
        int ans=0;
        if(is_sorted(a.begin(),a.end()))ans++;
        int prevmx =0;
        if(check(a,0,n-1,prevmx))ans=ans+n;
        vector<int>b=a;
        sort(b.begin(),b.end());
        for(int i=0;i<div.size();i++){
            int x = div[i];
            int c = (n/x);
            int l = 0; int r = x-1;bool xx=true;
            prevmx=0;
            while(c--){
              if(check(a,l,r,prevmx)==false){xx=false;break;}
              else{
                l=r+1;r=(l+x-1);
              }
            }
            if(xx){
                ans=ans+x;
            }
        }
        return ans;
    }
};
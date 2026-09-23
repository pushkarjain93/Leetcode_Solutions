class Solution {
public:
    int minOperations(vector<int>& a, int x) {
        int n = a.size();
        int s = accumulate(a.begin(),a.end(),0);
        int t = s-x;
        if(t<0)return -1;
        if(t==0)return n;
        int i=0;
        int temp=a[i];
        int j=1;
        int mx = -1;
        while(j<=n && i<n){
           if(temp<t && j<n){
            temp+=a[j];j++;
           }
           else{
            if(temp==t){
                mx=max(mx,j-i);
            }
            temp-=a[i];i++;
           }
        }
    
        if(temp == t)mx=max(mx,j-i);
        if(mx==-1)return mx;
        return n-mx;
    }
};
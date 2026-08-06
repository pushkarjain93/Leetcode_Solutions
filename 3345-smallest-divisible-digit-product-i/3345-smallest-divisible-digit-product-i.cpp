class Solution {
public:
int p (int nn){
    int n=nn;
    int ans =1;
    while(n){
      int x = n%10;
      ans=ans*x;
      n/=10;
    }return ans;
}
    int smallestNumber(int n, int t) {
        while(1){
          if(p(n)%t==0)return n;
          else n++;
        }
        return 0;
    }
};
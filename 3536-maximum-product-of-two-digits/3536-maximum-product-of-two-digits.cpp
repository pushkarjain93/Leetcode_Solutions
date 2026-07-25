class Solution {
public:
    int maxProduct(int n) {
        int x = n;
        int f = 0;
        int s = 0;
        while(x>0){
          int r = x % 10;
          if(r >= f){s=f;f=r;}
          else if(r<f && r>s){s=r;}
          x=x/10;
        }return (f * s);
    }
};
class Solution {
public:
    bool sumGame(string a) {
        int c = count(a.begin(),a.end(),'?');;
        if(c%2){
            return true;
        }
        int l = 0;int r = 0;
        int lq = 0; int rq = 0;
        int n = a.size();
        for(int i=0;i<n;i++){
            if(i<(n/2)){
               if(a[i]=='?'){
                  lq++;
               }
               else{
                 l+=a[i]-'0';
               }
            }
            else{
                 if(a[i]=='?'){
                   rq++;
               }
               else{
                 r+=a[i]-'0';
               }
            }
        }
        // cout<<lq<<' '<<rq<<' '<<l<<' '<<r;
        if(lq<rq){
           rq-=lq;
           lq=0;
           if(r>=l){
            return true;
           }
           else{
            int mn = 0;
            int mx = (rq/2)*9;
             int d = l-r;
             int f = d-mn;
             int s = d-mx;
             if(f>=0 && s>=0 && f<=mx && s<=mx)return false;
             return true;
           }
        }
        else if(lq==rq){
          if(l==r)return false;
          else return true;
        }
        else{
        lq-=rq;
           rq=0;
           if(l>=r){
            return true;
           }
           else{
              int mn = 0;
            int mx = (lq/2)*9;
             int d = r-l;
             int f = d-mn;
             int s = d-mx;
             if(f>=0 && s>=0 && f<=mx && s<=mx)return false;
             return true;
           }
        }
        return true;
    }
};
class Solution {
public:
int d(int n,int &p){
    int nn =n;int s=0;
    while(nn){
        s+=(nn%10);
        p=p*(nn%10);
        nn=nn/10;
    }
    return s;
}
    bool checkDivisibility(int n) {
        int p=1;
        int s = d(n,p);
        cout<<s<<' '<<p;
        s+=p;
        if(n%s==0)return true;
        return false;
    }
};
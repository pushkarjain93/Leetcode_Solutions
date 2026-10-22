class Solution {
public:
bool check(vector<int>&a){
    int x=0;
    for(int i=1;i<a.size();i++){
       if(a[i-1]<a[i])x++;
    }
    if(a[a.size()-1]<a[0])x++;
    if(x==(a.size()-1))return true;
    return false;
}
bool cc(vector<int>&a){
    int x=0;
    for(int i=1;i<a.size();i++){
       if(a[i-1]>a[i])x++;
    }
    if(a[a.size()-1]>a[0])x++;
    if(x==(a.size()-1))return true;
    return false;
}
    int minOperations(vector<int>& a) {
        if(check(a) ==false && cc(a)==false)return -1;
        int ans1=0;
        if(check(a)){
           for(int i=0;i<a.size();i++){
            if(a[i]==0){ans1=i;break;}
           }
           cout<<ans1<<'\n';
        }
        else{
            ans1=1;
          for(int i=0;i<a.size();i++){
            if(a[i]==(a.size()-1)){ans1+=i;break;}
          }
        }
        int ans2=1;
        reverse(a.begin(),a.end());
        if(check(a)){
           for(int i=0;i<a.size();i++){
            if(a[i]==0){ans2+=i;break;}
           }
        }
        else{
            ans2=2;
          for(int i=0;i<a.size();i++){
            if(a[i]==(a.size()-1)){ans2+=i;break;}
          }
        }
        cout<<ans1<<' '<<ans2;
       return min(ans1,ans2);
    }
};
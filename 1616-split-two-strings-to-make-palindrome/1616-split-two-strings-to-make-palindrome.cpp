class Solution {
public:
bool ispal(string a){
  for(int i=0;i<a.size();i++){
    if(a[i]!=a[a.size()-i-1])return false;
  }
  return true;
}
string fun(string &a,string &b){
     int i = 0;int j = b.size()-1;
        while(i<j){
            if(a[i]==b[j]){
                i++;j--;
            }
            else{
                break;
            }
        }
        string z = "";
           for(int p=0;p<i;p++)z+=a[p];
           for(int p=i;p<a.size();p++)z+=b[p];
       return z;
}
    bool checkPalindromeFormation(string a, string b) {
        if(ispal(a)||ispal(b))return true;
       string x = fun(a,b);
       string y = fun(b,a);
       reverse(a.begin(),a.end());
       reverse(b.begin(),b.end());
       string c = fun(a,b);
       string d = fun(b,a);
       if(ispal(x)||ispal(y)||ispal(c)||ispal(d))return true;
       return false;
    }
};
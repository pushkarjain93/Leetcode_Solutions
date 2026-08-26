class Solution {
public:
static bool ss (string a,string b){
    if(a.size()!=b.size())return a.size()<b.size();
    return a<b;
}
    string shortestBeautifulSubstring(string s, int k) {
        int n = s.size();
        int l = 0;
        int x;
        vector<string>v;
        for(int i=0;i<n;i++){
            x=0;
            for(int j=i;j<n;j++){
                if(s[j]=='1')x++;
                if(x==k){
                    v.push_back(s.substr(i,j-i+1));break;
                }
            }
        }
        if(v.size()==0)return "";
        sort(v.begin(),v.end(),ss);
        return v[0];
    }
};
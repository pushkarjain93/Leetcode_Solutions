class Solution {
public:
bool check(unordered_map<char,int>&f,unordered_map<char,int>&g){
    for(auto num:g){
       if(f[num.first]<num.second)return false;
    }
    return true;
}
    string minWindow(string s, string t) {
        unordered_map<char,int>f;
        unordered_map<char,int>g;
        int n=s.size();
        for(auto num:t){
            g[num]++;
        }
        int l=0;int mn=INT_MAX;string ans="";
        for(int h=0;h<n;h++){
           f[s[h]]++;
           if(check(f,g)){
            while(l<=h && check(f,g)){
                f[s[l]]--;
                l++;
            }
            if(h-l+2 < mn){
             mn=h-l+2;
             ans=s.substr(l-1,mn);
            }
           }
        }
        return ans;
    }
};
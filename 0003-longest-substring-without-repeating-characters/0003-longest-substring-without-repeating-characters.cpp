class Solution {
public:
bool check(int l , int r,unordered_map<char,int>&f){
    for(auto num:f){
        if(num.second>1)return false;
    }
    return true;
}
    int lengthOfLongestSubstring(string s) {
        unordered_map<char,int>f;
        int n=s.size();
        int l=0;int h=0;int mx =0;
        for(h=0;h<n;h++){
            f[s[h]]++;
           if(check(l,h,f)==true){mx=max(mx,h-l+1);continue;}
           while(check(l,h,f)==false){
            f[s[l]]--;l++;
           }
           mx=max(mx,h-l+1);
        }
        return mx;
    }
};
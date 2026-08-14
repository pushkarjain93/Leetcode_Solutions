class Solution {
public:
    int maximumLengthSubstring(string s) {
        int n =s.size();
        int l=0;int mx=0;
        unordered_map<char,int>f;
        for(int h=0;h<n;h++){
            f[s[h]]++;
            while(f[s[h]]>2){
                mx=max(mx,h-l);
                f[s[l]]--;l++;
            }
        }mx=max(mx,n-l);return mx;
    }
};
class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        unordered_map<char,int>f;
        int n=s.size();
        int l=0;int h=0;int mx =0;
        for(h=0;h<n;h++){
            f[s[h]]++;
           while(f[s[h]]>1){
            f[s[l]]--;l++;
           }
           mx=max(mx,h-l+1);
        }
        return mx;
    }
};
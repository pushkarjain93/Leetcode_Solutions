class Solution {
public:
    int minimumLength(string s) {
        vector<int>a(26,0);
        for(int i=0;i<s.size();i++){
            a[s[i]-'a']++;
        }int ans=0;
        for(int i=0;i<26;i++){
           if(a[i]==0)continue;
           if(a[i]%2){
               ans++;
           }
           else{
            ans+=2;
           }
        }
        return ans;
    }
};
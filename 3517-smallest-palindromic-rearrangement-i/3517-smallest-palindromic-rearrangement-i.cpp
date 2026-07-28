class Solution {
public:
    string smallestPalindrome(string s) {
        int n=s.size();
        
        string ans;
          ans.resize(n);
        vector<int>v(26,0);
        for(int i=0;i<n;i++){
            v[s[i]-'a']++;
        }
        int l=0;int m=n-1;
        for(char i='a';i<='z';i++){
         if(v[i-'a']%2 == 1){
            ans[n/2]=i;v[i-'a']--;
         }
          if(v[i-'a']==0)continue;
            int x = v[i-'a'];
        while(l<=m){
            ans[l]=i;x--;l++;
            ans[m]=i;x--;m--;
            if(x<=0)break;
           }
        }
       return ans;
    }
};
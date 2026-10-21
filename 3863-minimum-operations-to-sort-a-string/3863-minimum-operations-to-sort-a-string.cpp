class Solution {
public:
    int minOperations(string s) {
        string b = s;
        sort(b.begin(),b.end());
        if(s==b)return 0;
        if(s.size()==2)return -1;
        int l=0;int h=0;
        unordered_map<char,int>f;
        for(auto num:s)f[num]++;
        for(int i=0;i<s.size();i++){
            if(s[i]!=b[i]){l=i;break;}
        }
        if(l!=0)return 1;
        l=0;
        for(int i=s.size()-1;i>=0;i--){
            if(s[i]!=b[i]){l=i;break;}
        }
        if(l!=(s.size()-1))return 1;
        
        if(s[0]!=b[s.size()-1] || s[s.size()-1]!=b[0])return 2;
        else{
            if(f[s[0]]>1 || f[s[s.size()-1]]>1)return 2;
        }
        return 3;
    }
};
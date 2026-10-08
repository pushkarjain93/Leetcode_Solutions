class Solution {
public:
    string removeOuterParentheses(string s) {
        int n=s.size();string temp="";int x=0;
        for(int i=0;i<n;i++){
            if(s[i]=='('){
                if(x!=0)temp+=s[i];
                x++;
            }
            else{
              x--;if(x!=0)temp+=s[i];
            }
           
        }
        return temp;
    }
};
class Solution {
public:
    bool isValid(string s) {
        stack<char>st;
        unordered_map<char,char>f;
        f['(']=')';
        f['[']=']';
        f['{']='}';
        for(int i=0;i<s.size();i++){
            if(s[i]=='('||s[i]=='{'||s[i]=='[')st.push(s[i]);
            else{
                if(st.size()==0)return false;
               if(f[st.top()]==s[i])st.pop();
               else return false;
            }
        }
        if(st.size()==0)return true;
        return false;
    }
};
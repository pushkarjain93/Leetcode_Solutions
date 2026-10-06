class Solution {
public:
    int minAddToMakeValid(string s) {
        stack<char>st;int x=0;
        for(int i=0;i<s.size();i++){
            if(s[i]=='('){st.push(s[i]);x++;}
            else {
                if(x>0){st.pop();x--;}
                else{
                    st.push(')');
                }
            }
        }return st.size();
    }
};
class Solution {
public:
    int scoreOfParentheses(string s) {
        stack<string>st;
        for(int i=0;i<s.size();i++){
            if(s[i]=='(')st.push("(");
            else{
                int x=0;
                while(st.top()!="("){
                   x+=stoi(st.top());st.pop();
                }
                st.pop();
                if(x==0)st.push(to_string(x+1));
                else st.push(to_string((2*x)));
            }
        }
        int ans=0;
        while(st.size()>0){
            ans+=stoi(st.top());
            st.pop();
        }
        return ans;
    }
};
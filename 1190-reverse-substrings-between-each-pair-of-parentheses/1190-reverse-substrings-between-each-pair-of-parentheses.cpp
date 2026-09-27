class Solution {
public:
    string reverseParentheses(string s) {
        s.push_back(')');
        reverse(s.begin(),s.end());
        s.push_back('(');
        reverse(s.begin(),s.end());
        stack<int>st;string ans="";
        for(int i=0;i<s.size();i++){
            if(s[i]==')'){
                vector<char>temp;
                while(st.top()!='('){
                   temp.push_back(st.top());st.pop();
                }
                st.pop();
                if(i==s.size()-1){
        for(int j=0;j<temp.size();j++)ans.push_back(temp[j]);break;
                }
                for(int j=0;j<temp.size();j++)st.push(temp[j]);

            }
            else st.push(s[i]);
        }
        reverse(ans.begin(),ans.end());
        return ans;
    }
};
class Solution {
public:
bool valid(string &s){
    int x=0;
       for(int i=0;i<s.size();i++){
            if(s[i]=='('){x++;}
            else if(s[i]==')'){
              x--;
              if(x<0)return false;
            }
        }
        if(x==0)return true;
        return false;
}
void rec(int i,string &s,int mn,string &temp,set<string>&ans){
  if(i==s.size()){
        if(mn==0){
      if(temp.size()>0 && valid(temp)==true){
        ans.insert(temp);
      }
  }
    return;
  }
 
  if((s[i]!='(') && (s[i]!=')')){
    temp.push_back(s[i]);
  rec(i+1,s,mn,temp,ans);
  temp.pop_back();
  }

  else{
    temp.push_back(s[i]);
    rec(i+1,s,mn,temp,ans);
    temp.pop_back();
    
    if(mn!=0)rec(i+1,s,mn-1,temp,ans);}
}
    vector<string> removeInvalidParentheses(string s) {
        stack<char>st;int x=0;
        for(int i=0;i<s.size();i++){
            if(s[i]=='('){st.push(s[i]);x++;}
            else if(s[i]==')'){
               if(x>0){
                st.pop();x--;
               }
               else{
                st.push(')');
               }
            }
        }
        int mn = st.size();
        if(mn==0)return{s};
        map<string,int>f;
        set<string>ss;
        vector<string>ans;
        string temp="";
        rec(0,s,mn,temp,ss);
        if(ss.size()==0)return {""};
        for(auto num:ss)ans.push_back(num);
        return ans;
    }
};
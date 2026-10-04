class Solution {
public:
    bool checkValidString(string s) {
        stack<int>s1;
        stack<int>s2;
        for(int i=0;i<s.size();i++){
            if(s[i]=='('){s1.push(i);}
            else if(s[i]=='*'){s2.push(i);}
            else {
                if(s1.size()>0){s1.pop();}
                else if(s2.size()>0){s2.pop();}
                else{
                    return false;
                }
            }
        }
        if(s1.size()==0)return true;
        if(s2.size()<s1.size())return false;
       while(s1.size()>0){
        if(s1.top()<s2.top()){s1.pop();s2.pop();}
        else return false;
       }
        return true;

    }
};
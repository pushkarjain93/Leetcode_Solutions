class Solution {
public:
    bool checkString(string s) {
        int x=0;
        for(int i=0;i<s.size();i++){
            if(s[i]=='b')x=1;
            else{
                if(x==1)return false;
            }
        }
        return true;
    }
};
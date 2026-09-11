class Solution {
public:
    long long smallestNumber(long long a) {
        if(a<0){
            a=-a;
            string s = to_string(a);
            sort(s.rbegin(),s.rend());
            a = stoll(s);
            return -a;
        }
        string s = to_string(a);
        sort(s.begin(),s.end());
        for(int i=0;i<s.size();i++){
            if(s[i]!='0'){
                swap(s[0],s[i]);
                break;
            }
        }
        a = stoll(s);
        return a;
    }
};
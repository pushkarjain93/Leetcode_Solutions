class Solution {
public:
    string maxSumOfSquares(int n, int s) {
        if((n*9)<s)return "";
        string ans="";
        while(s>=9){
            ans+="9";
            s-=9;
        }
        if(ans.size()<n)ans+=to_string(s);
        while(ans.size()<n)ans+="0";
        return ans;
    }
};
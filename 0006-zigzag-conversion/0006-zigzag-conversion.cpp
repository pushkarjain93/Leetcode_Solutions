class Solution {
public:
    string convert(string ss, int s) {
        if(s==1)return ss;
        vector<vector<char>>v(s,vector<char>(ss.size(),'%'));
        int l=0;int i=0;int j=0;
        while(l<ss.size()){
            if(i<s){
                v[i][j]=ss[l];
                l++;
                i++;
            }
            else{
                i=i-2;
                 j++;
                while(l<ss.size() && i!=0){
                 v[i][j]=ss[l];
                 i--;j++;
                 l++;
                }
            }
        }
        string ans="";
        for(int i=0;i<v.size();i++){
            for(int j=0;j<v[i].size();j++){
                if(v[i][j]!='%')ans=ans+v[i][j];
            }
        }
        return ans;
    }
};
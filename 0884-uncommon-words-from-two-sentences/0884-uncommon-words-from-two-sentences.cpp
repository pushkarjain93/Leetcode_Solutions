class Solution {
public:
    vector<string> uncommonFromSentences(string a, string b) {
        map<string,int>f;
        string temp="";
        for(int i=0;i<a.size();i++){
            if(a[i]!=' ')temp+=a[i];
            if((a[i]==' ') || (i==a.size()-1)){
            f[temp]++;
              temp="";
            }
        }
        temp="";
        for(int i=0;i<b.size();i++){
            if(b[i]!=' ')temp+=b[i];
            if(b[i]==' ' || (i==b.size()-1)){
            cout<<temp<<'\n';
            f[temp]++;
              temp="";
            }
        }
        cout<<f["banana"];
        vector<string>ans;
        for(auto num:f){
            if(num.second==1)ans.push_back(num.first);
        }
        return ans;
    }
};
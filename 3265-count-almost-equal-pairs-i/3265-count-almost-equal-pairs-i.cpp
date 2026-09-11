class Solution {
public:
    int countPairs(vector<int>& a) {
        vector<string>b;
        for(int i=0;i<a.size();i++){
            b.push_back(to_string(a[i]));
        }
        int mx = 0;
        for(int i=0;i<b.size();i++){
            int l = b[i].size();
           mx = max(mx,l);
        }
        for(int i=0;i<b.size();i++){
           int x = mx-b[i].size();
           string temp="";
           for(int j=0;j<x;j++){
            temp+="0";
           }
           b[i]=temp+b[i];
        }
        int ans =0;
        for(int i=0;i<b.size();i++){
            for(int j=0;j<b.size();j++){
                if(i==j)continue;int x =0;
                for(int k=0;k<b[j].size();k++){
                    if(b[i][k]!=b[j][k])x++;
                }
                if(x==0){
                ans++;
                }
                else if(x==2){
                    string aa = b[i];
                    string bb = b[j];
                    sort(aa.begin(),aa.end());
                    sort(bb.begin(),bb.end());
                    if(aa==bb)ans++;
                }
            }
        }
        return ans/2;
    }
};
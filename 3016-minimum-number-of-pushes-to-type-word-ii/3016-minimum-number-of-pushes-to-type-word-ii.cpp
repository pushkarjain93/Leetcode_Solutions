class Solution {
public:
bool static st(pair<char,int>&a,pair<char,int>&b){
    return a.second>b.second;
}
    int minimumPushes(string word) {
        vector<pair<char,int>>f(26,{'a',0});
        unordered_map<char,int>g;
        for(int i = 0; i<word.size();i++){
            f[word[i]-'a'].first = word[i];
            f[word[i]-'a'].second++;
        }
        int x = 0;
        int ans=0;
        sort(f.begin(),f.end(),st);
        for(int i=0;i<f.size();i++){
            if(f[i].second == 0)break;
            if(g.size()<8){
                 g[f[i].first]=1;
            }
            else if(g.size()<16){
                 g[f[i].first]=2;
            }
            else if(g.size()<24){
                 g[f[i].first]=3;
            }
            else g[f[i].first]=4;
        }
        for(int i=0;i<word.size();i++){
            ans+=g[word[i]];
        }
        return ans;
    }
};
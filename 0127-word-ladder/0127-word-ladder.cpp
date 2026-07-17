class Solution {
public:
    int ladderLength(string a, string b, vector<string>& w) {
        int n=a.size();
        unordered_map<string,int>f;
        unordered_map<string,int>g;
        for(auto num:w){
            g[num]++;
        }
        queue<pair<string,int>>q;q.push({a,0});
        int ans=INT_MAX;
        while(!(q.empty())){
            string s=q.front().first;
            int t=q.front().second;q.pop();
            if(s==b){ans=min(ans,t);}
            int ss=0;string temp=s;
            while(ss<s.size()){
            for(char i='a';i<='z';i++){
                temp[ss]=i;
                if(g[temp]>0){q.push({temp,t+1});g[temp]=0;}
            }temp=s;
            ss++;
            }
        }
        if(ans==INT_MAX)return 0;
        return ans+1;
    }
};
class Solution {
public:

    bool check(unordered_map<char,int>&mp1,unordered_map<char,int>&mp2){
        for(auto it:mp1){
            if(mp2[it.first]<it.second)return false;
        }
        return true;
    }
    string minWindow(string s, string t) {
        unordered_map<char,int>mp1,mp2;
        for(auto it:t){
            mp1[it]++;
        }
        int n=s.size();
        int lo=0;
        int hi=0;
        int mini=1e6;
        string ans="";
        for( ;hi<n;hi++){
            mp2[s[hi]]++;
            if((hi-lo)+1>=t.size()){
                bool flg=false;
                 while(hi-lo+1>=t.size() && check(mp1,mp2)){
                    flg=true;
                    mp2[s[lo]]--;
                    if(mp2[s[lo]]==0)mp2.erase(s[lo]);
                    lo++;
                 }
                 if(flg){
                    lo--;
                    mp2[s[lo]]++;
                    if(check(mp1,mp2) && hi-lo+1<mini){
                        mini=hi-lo+1;
                        ans=s.substr(lo,hi-lo+1);
                    }
                    mp2[s[lo]]--;
                    lo++;
                 }
                 
            }
        }
        return ans;
    }
};
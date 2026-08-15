class Solution {
public:
    int longestSubsequence(vector<int>& a) {
        int x=0;int cnt=0;
        for(int i=0;i<a.size();i++){
            x=x^a[i];
            if(a[i]==0)cnt++;
        }
        if(cnt == a.size())return 0;
        if(x!=0)return a.size();
        else return a.size()-1;
    }
};
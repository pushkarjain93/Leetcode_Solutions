class Solution {
public:
    int longestConsecutive(vector<int>& a) {
        unordered_set<int>s;
        for(int i=0;i<a.size();i++){
           s.insert(a[i]);
        }
        int ans=0;int l=0;
        for(auto num:s){
            if(s.find(num-1)==s.end()){
                int x = num;l=0;
                while(s.find(x)!=s.end()){
                    x++;l++;
                }
            }
            ans=max(ans,l);
        }
        return ans;
    }
};
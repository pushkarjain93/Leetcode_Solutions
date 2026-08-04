class Solution {
public:
    vector<int> findMissingElements(vector<int>& a) {
       int mn = *min_element(a.begin(),a.end());
       int mx = *max_element(a.begin(),a.end());
       unordered_map<int,int>f;
       for(auto num:a)f[num]++;
       vector<int>ans;
       for(int i = mn; i<=mx;i++){
         if(f[i]==0){
            ans.push_back(i);
         }
       }
       return ans;
    }
};
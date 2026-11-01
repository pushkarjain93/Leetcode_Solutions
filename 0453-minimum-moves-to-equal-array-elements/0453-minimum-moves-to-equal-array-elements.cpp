class Solution {
public:
    int minMoves(vector<int>& a) {
        int mn = *min_element(a.begin(),a.end());
        int ans=0;
        for(int i=0;i<a.size();i++){
          ans=ans+(a[i]-mn);
    }
        return ans;
    }
};
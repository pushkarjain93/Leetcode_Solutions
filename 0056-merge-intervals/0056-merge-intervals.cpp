class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& a) {
        int n = a.size();
        vector<vector<int>>ans;
        if(n==1)return a;
        // {a1 , a2} {b1 , b2}
        // case1: if b2 is between a1 and a2 right is max(a2,b2);
        // case2: not between then a1 is curr element now
        sort(a.begin(),a.end());
           int a1 = a[0][0];int a2 = a[0][1];
          for(int i=1;i<n;i++){
            if(a[i][0]<=a2){
                a2=max(a2,a[i][1]);
            }
            else{
                ans.push_back({a1,a2});
                a1=a[i][0];
                a2=a[i][1];
            }
             if(i==n-1){
                    ans.push_back({a1,a2});
                }
          }
           return ans;
        }
    
};
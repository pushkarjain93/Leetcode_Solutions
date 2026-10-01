class Solution {
public:
    vector<vector<int>> kClosest(vector<vector<int>>& a, int k) {
        vector<pair<double,int>>p;
        for(int i=0;i<a.size();i++){
            int x = a[i][0];
            int y = a[i][1];
            double dist = 1.0*sqrt((x*x)+(y*y));
            p.emplace_back(dist,i);
        }
        sort(p.begin(),p.end());
        vector<vector<int>>ans;
        for(int i=0;i<k;i++){
            ans.push_back({a[p[i].second]});
        }
        return ans;
    }
};
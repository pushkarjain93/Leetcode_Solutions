class Solution {
public:
    vector<int> topKFrequent(vector<int>& a, int k) {
        unordered_map<int,int>f;
        for(auto num:a){
            f[num]++;
        }
        priority_queue<pair<int,int>,vector<pair<int,int>>,greater<>>pq;
       for(auto num:f){
        pq.push({num.second,num.first});
        if(pq.size()>k)pq.pop();
       }
       vector<int>ans;
        while(pq.size()>0){
               ans.push_back(pq.top().second);pq.pop();
        }return ans;
    }
};
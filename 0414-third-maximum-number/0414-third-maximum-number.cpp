class Solution {
public:
    int thirdMax(vector<int>& a) {
        unordered_set<int>s;int mx =0;
        for(auto num:a){mx=max(num,mx);s.insert(num);}
        priority_queue<int,vector<int>,greater<>>pq;
        for(auto num:s){
            pq.push(num);
            if(pq.size()>3)pq.pop();
        }
        if(pq.size()<3)return mx;
        return pq.top();
    }
};
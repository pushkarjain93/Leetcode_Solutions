class FindSumPairs {
public:
    unordered_map<int,int>f;vector<int>a;vector<int>b;
    FindSumPairs(vector<int>& o, vector<int>& e) {
        a=o;b=e;
        for(int i=0;i<b.size();i++)f[b[i]]++;
    }
    void add(int index, int val) {
       f[b[index]]--;
        b[index]+=val;
       f[b[index]]++;
    }
    
    int count(int tot) {
        int ans = 0;
        for(auto num:a){
           if(f[tot-num]>0)ans+=f[tot-num];
        }return ans;
    }
};

/**
 * Your FindSumPairs object will be instantiated and called as such:
 * FindSumPairs* obj = new FindSumPairs(nums1, nums2);
 * obj->add(index,val);
 * int param_2 = obj->count(tot);
 */
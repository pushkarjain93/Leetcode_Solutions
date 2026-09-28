class Solution {
public:
    int subarraySum(vector<int>& a, int k) {
        unordered_map<int,int>f;int n=a.size();int x=0;int cnt=0;
        f[0]=1;
        for(int i=0;i<n;i++){
             x=x+a[i];
             cnt=cnt+f[x-k];
             f[x]++;
        }
        return cnt;
    }
};
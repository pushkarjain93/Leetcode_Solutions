class Solution {
public:
    int largestInteger(vector<int>& a, int k) {
        int n=a.size();
        unordered_map<int,int>f;
        for(int i=0;i<=n-k;i++){
           for(int j=i;j<i+k;j++){
            if(f.find(a[j])!=f.end()){
                 if(f[a[j]]==i)continue;
                 else f[a[j]]=-1;
                }
                else f[a[j]]=i;
           }
        }
        int ans=-1;
        for(auto num:f){
            if(num.second!=-1){ans=max(ans,num.first);}
        }
        return ans;
    }
};
class Solution {
public:
    int numOfSubarrays(vector<int>& a, int k, int x) {
        int i=0;int s=0;
        for(int j=0;j<k;j++){
          s+=a[j];
        }
        int j=k-1;int ans=0;
        if((s/k)>=x){
                ans++;
            }
                        if(j==a.size()-1)return ans;
        while(1){
            s-=a[i];
            i++;
            j++;
            s+=a[j];
            if((s/k)>=x){
                ans++;
            }
            if(j==a.size()-1)break;
        }
        return ans;
    }
};
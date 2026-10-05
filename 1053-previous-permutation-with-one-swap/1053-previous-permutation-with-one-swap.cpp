class Solution {
public:
    vector<int> prevPermOpt1(vector<int>& a) {
        int mn=0;int l=-1;int m=-1;
        for(int i=a.size()-2;i>=0;i--){
            for(int j=i;j<a.size();j++){
                if(a[j]<a[i]){
                    if(mn<a[j]){
                        mn=a[j];l=j;m=i;
                    }
                   mn=max(mn,a[j]);
                }
            }
            if(mn!=0)break;
        }
         if(mn==0)return a;
         swap(a[l],a[m]);
         return a;
    }
};
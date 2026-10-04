class Solution {
public:
    int maxSumTwoNoOverlap(vector<int>& v, int f, int s) {
        vector<vector<int>>a;
        vector<vector<int>>b;
        int ss=0;int l=0;int h=f-1;
        for(int i=0;i<f;i++){
           ss+=v[i];
        }
        while(l<=h){
        a.push_back({ss,l,h});
        if(h==v.size()-1)break;
        ss=ss-v[l];
        l++;
        h++;
        ss=ss+v[h];
        }
        l=0;h=s-1;ss=0;
         for(int i=0;i<s;i++){
           ss+=v[i];
        }
        while(l<=h){
        b.push_back({ss,l,h});
        if(h==v.size()-1)break;
        ss=ss-v[l];
        l++;
        h++;
        ss=ss+v[h];
        }
        int ans=0;

      
        for(int i=0;i<a.size();i++){
            for(int j=0;j<b.size();j++){
                if((a[i][2]<b[j][1] ) || (a[i][1]>b[j][2]))ans=max(ans,a[i][0]+b[j][0]);
            }
        }
        return ans;
    }
};
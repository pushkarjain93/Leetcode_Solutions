class Solution {
public:
    int firstMissingPositive(vector<int>& a) {
        int n = a.size();
        for(int i=0;i<n;i++){
            if(a[i]>n || a[i]<=0)a[i]=n+1;
        }
        // 3 4 5 1
        for(int i=0;i<n;i++){
            if(abs(a[i])>n)continue;
           if( a[abs(a[i])-1] < 0) continue;
                a[abs(a[i])-1]=-a[abs(a[i])-1];
        }
        int ans = n+1;
        for(int i =0;i<n;i++){
            if(a[i]<0)continue;
            ans=i+1;break;
        }return ans;
    }
};
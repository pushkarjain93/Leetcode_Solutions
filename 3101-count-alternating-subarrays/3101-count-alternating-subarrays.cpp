class Solution {
public:
    long long countAlternatingSubarrays(vector<int>& a) {
        long long int x=1;long long int ans=0;
        for(int i=0;i<a.size()-1;i++){
            if(a[i]!=a[i+1]){
             x++;
             if(i==a.size()-2){
                x--;
                ans+=((x*1ll*(x+1))/2);
             }
            }
            else{
                x--;
                ans+=((x*1ll*(x+1))/2);x=1;
            }
        }
        return ans+a.size();
    }
};
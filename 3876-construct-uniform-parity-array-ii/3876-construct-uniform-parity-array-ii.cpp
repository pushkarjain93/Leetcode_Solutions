class Solution {
public:
    bool uniformArray(vector<int>& a) {
        sort(a.begin(),a.end());
        int e=0;int o=0;
        if(a[0]%2){o++;return true;}
        else e++;
        for(int i=1;i<a.size();i++){
            if(a[i]%2){
                if(o==0)return false;
                o++;
            }
          }
        return true;
        }
};
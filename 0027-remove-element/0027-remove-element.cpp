class Solution {
public:
    int removeElement(vector<int>& a, int val) {
        int j;
        for(int i=a.size()-1;i>=0;i--){
            if(a[i]!=val){j=i;break;}
        }
        int n = a.size();
        int i=0;
        while(i<=j){
           if(a[i]==val){
            swap(a[i],a[j]);
            while(a[j]==val)j--;
           }
           i++;
        }
        return i;
    }
};
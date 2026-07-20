class Solution {
public:
    vector<vector<int>> shiftGrid(vector<vector<int>>& a, int k) {
        int n=a.size();int m=a[0].size();
        vector<int>temp;
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                temp.push_back(a[i][j]);
            }
        }
        reverse(temp.begin(),temp.end());k=k%temp.size();
        rotate(temp.begin(),temp.begin()+k,temp.end());int x=0;
                reverse(temp.begin(),temp.end());
          for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                a[i][j]=temp[x];x++;
            }
        }return a;
    }
};
class Solution {
public:
    vector<int> resultArray(vector<int>& a) {
        vector<int>a1;
        vector<int>a2;
        a1.push_back(a[0]);
        a2.push_back(a[1]);
        for(int i=2;i<a.size();i++){
            if(a1.back()>a2.back()){
                a1.push_back(a[i]);
            }
            else a2.push_back(a[i]);
        }
        for(int i=0;i<a1.size();i++){
           a[i]=a1[i];
        }
        for(int i=0;i<a2.size();i++){
            a[a1.size()+i]=a2[i];
        }return a;
    }
};
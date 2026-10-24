class Solution {
public:
    int countDaysTogether(string aa, string la, string ab, string lb) {
        vector<int>v{0,31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};

        string aam = aa.substr(0, 2);
        string alm = la.substr(0, 2); 
        string bam = ab.substr(0, 2);
        string blm = lb.substr(0, 2); 

        string aad = aa.substr(3, 2);
        string ald = la.substr(3, 2); 
        string bad = ab.substr(3, 2);
        string bld = lb.substr(3, 2); 

        int a=stoi(aad);int b=stoi(ald);int c=stoi(bad);int d=stoi(bld);
          for(int i=0;i<stoi(aam);i++){
             a+=v[i];
          }
          for(int i=0;i<stoi(alm);i++){
             b+=v[i];
          }
          for(int i=0;i<stoi(bam);i++){
             c+=v[i];
          }
          for(int i=0;i<stoi(blm);i++){
             d+=v[i];
          }
        if(d<a || c>b)return 0;
        int ans = abs(max(a,c)-min(b,d));
        return ans+1;
    }
};
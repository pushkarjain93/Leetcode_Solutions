class Solution {
public:
    int totalNumbers(vector<int>& digits) {
        int a,b,c;
        map<int,int>freq;
        vector<int>v;
        for(auto num:digits){
            freq[num]++;
        }
        for(int i=100;i<999;i=i+2){
            a=i%10;
            b=(i/10)%10;
            c=(i/100)%10;
            if(freq[a]>0 && freq[b]>0 && freq[c]>0){
                     if(a==b && freq[a]>=2 && freq[b]>=2 && b!=c){
                              v.push_back(i);      
                     }
                  else   if(b==c && freq[b]>=2 && freq[c]>=2 && a!=b){
                        v.push_back(i);
                     }
                 else    if(a==c && freq[a]>=2 && freq[c]>=2 && c!=b){
                        v.push_back(i);
                     }
                 else    if(freq[a]>=1 && freq[b]>=1 && freq[c]>=1 && a!=b && b!=c && c!=a){
                        v.push_back(i);
                     }
                  else   if(a==b && b==c && c==a && freq[a]>=3 && freq[b]>=3 && freq[c]>=3){
                        v.push_back(i);
                     }
            }
        }
   return v.size();
    }
};
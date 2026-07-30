class Solution {
public:
    int minimumPushes(string word) {
       // i =0 to 7 tak add 1 in ans
       // i =8 to 15 tak add 2 in ans
       // i =16 to 23 tak add 3 in ans
       // i =24 to 26 tak add 4 in ans
       int ans = 0;
       for(int i = 0 ; i < word.size(); i++){
        if(i>=0 && i<=7){ans++;}
       else if(i>=8 && i<=15){ans=ans+2;}
       else if(i>=16 && i<=23){ans=ans+3;}
       else if(i>=24 && i<=26){ans=ans+4;}
       }return ans;
    }
};
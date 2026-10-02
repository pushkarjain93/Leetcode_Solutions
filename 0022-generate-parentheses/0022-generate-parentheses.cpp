class Solution {
public:
void rec(int l,int r,int x,vector<string>&ans,string temp){
   if(l==0 && r==0){
      ans.push_back(temp);
      return;
   }
   if(x>0 && r>0){
    temp+=")";
     rec(l,r-1,x-1,ans,temp);temp.pop_back();
   }
   if(l>0){
   temp+="(";
   rec(l-1,r,x+1,ans,temp);temp.pop_back();
   }
}
    vector<string> generateParenthesis(int n) {
        vector<string>ans;
        string temp="";
        int l=n;int r=n;int x=0;
        rec(l,r,x,ans,temp);
        return ans;
    }
};
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
void rec(TreeNode* a,vector<string>&v){
   if(a==NULL){
       v.push_back("#");
       return;
   }
   v.push_back(to_string(a->val));
   rec(a->left,v);
   rec(a->right,v);
 }
    bool isSubtree(TreeNode* a, TreeNode* b) {
        vector<string>aa;
        vector<string>bb;
        rec(a,aa);
        rec(b,bb);
        for(auto num:aa)cout<<num<<' ';cout<<'\n';
        for(auto num:bb)cout<<num<<' ';
        for(int i=0;i<aa.size();i++){
            int l = i;
            for(int j=0;j<bb.size();j++){
                if((aa[l]==bb[j])&&(j==bb.size()-1))return true;
                if(aa[l]!=bb[j])break;
                else l++;
            }
        }
       return false;
    }
};
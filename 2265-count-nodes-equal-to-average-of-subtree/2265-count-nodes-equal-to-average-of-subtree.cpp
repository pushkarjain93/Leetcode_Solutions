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
// {01 11 93 61 112 246}
int rec(TreeNode* root,int &ans,unordered_map<TreeNode*,int>&f){
  if(root==NULL){
    return 0;
  }
   int x = rec(root->left,ans,f);
   int y = rec(root->right,ans,f);
   int z = x+y+root->val;
   if(root->left == NULL && root->right == NULL){
    f[root]=1;ans++;
    return z;}
   if(root->left == NULL)f[root]=f[root->right]+1;
  else if(root->right == NULL)f[root]=f[root->left]+1;
   else f[root]=f[root->left]+f[root->right]+1;
   if((z/f[root])==root->val)ans++;
   return z;
}
    int averageOfSubtree(TreeNode* root) {
        int ans=0;
        unordered_map<TreeNode*,int>f;
        int x = rec(root,ans,f);
        return ans;
    }
};
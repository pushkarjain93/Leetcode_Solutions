/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
 void par(TreeNode* root,unordered_map<int,TreeNode*>&f){
   if(root==NULL)return;
   if(root->left == NULL && root->right == NULL)return;
   if(root->left)f[root->left->val]=root;
   if(root->right)f[root->right->val]=root;
   par(root->left,f);
   par(root->right,f);
 }
void huh(TreeNode* root,vector<int>&dist,int k,int x,unordered_map<int,TreeNode*>&f,unordered_map<TreeNode*, bool> &vis){
    if(root == NULL)return;
    vis[root]=1;
    if(k!=0 && k==x){dist.push_back(root->val);return;}
    if(root->left && vis[root->left]==0)huh(root->left,dist,k,x+1,f,vis);
    if(root->right && vis[root->right]==0)huh(root->right,dist,k,x+1,f,vis);
    if(vis[f[root->val]]==0)huh(f[root->val],dist,k,x+1,f,vis);
}
    vector<int> distanceK(TreeNode* root, TreeNode* target, int k) {
        // at every step we can go to its left, right or its parent, so use that thought
        if(k==0)return {target->val};
        unordered_map<int,TreeNode*>f;
        vector<int>dist;
        unordered_map<TreeNode*, bool> vis;
        par(root,f);
        huh(target,dist,k,0,f,vis);
        return dist;
    }
};
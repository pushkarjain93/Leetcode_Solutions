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
void rec(TreeNode* root,TreeNode* t,TreeNode* &ans){
    if(root==NULL)return;
    if(root->val == t->val){ans = root;return;}
   rec(root->left,t,ans);
   rec(root->right,t,ans);
}
    TreeNode* getTargetCopy(TreeNode* a, TreeNode* b, TreeNode* t) {
        TreeNode* ans= new TreeNode(0);
        rec(b,t,ans);
        return ans;
    }
};
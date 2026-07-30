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
int lh(TreeNode* root){
    if(root==NULL)return 0 ;
    return 1+lh(root->left);
}
int rh(TreeNode* root){
    if(root==NULL)return 0 ;
    return 1+rh(root->right);
}
int x (TreeNode* root){
    if(root==NULL)return 0;
    int l = lh(root);
    int r = rh(root);
    if(l==r){
        int xx =pow(2,l);
        return xx-1;
    }
    else{
       int a = x(root->left);
        int b = x(root->right);
        return a+b+1;
    }
}
    int countNodes(TreeNode* root) {
        return x(root);
    }
};
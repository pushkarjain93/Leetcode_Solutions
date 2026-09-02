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
bool rec(TreeNode* root){
    if(root==NULL)return false;
    bool l = rec(root->left);
    if(l==false)root->left = NULL;
    bool r = rec(root->right);
    if(r==false)root->right = NULL;
    if((root->val == 1) || (l||r)== true)return true;
    return false;
}
    TreeNode* pruneTree(TreeNode* root) {
        bool ans = rec(root);
        if (ans == false)return NULL;
        return root;
    }
};
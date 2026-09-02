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
bool rec(TreeNode* root,int target){
    if(root==NULL)return false;
    bool l = rec(root->left,target);
    if(l==false)root->left = NULL;
    bool r = rec(root->right,target);
    if(r==false)root->right = NULL;
    if((root->val != target) || (l||r)== true)return true;
    return false;
}
    TreeNode* removeLeafNodes(TreeNode* root, int target) {
         bool ans = rec(root,target);
        if (ans == false)return NULL;
        return root;
    }
};
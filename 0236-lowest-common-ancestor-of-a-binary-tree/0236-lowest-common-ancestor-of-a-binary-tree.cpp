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
TreeNode* findancestor(TreeNode* root,TreeNode* p ,TreeNode* q){
    if(root==NULL)return NULL;
    if(root== p || root==q){return root;}
    TreeNode* lft = findancestor(root->left,p,q); // lft=5;
    TreeNode* rght = findancestor(root->right,p,q); // rght=1;
    if(lft != NULL && rght != NULL){return root;}
    if(lft!=NULL){return lft;}
    return rght;
}
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        return findancestor(root,p,q);
    }
};
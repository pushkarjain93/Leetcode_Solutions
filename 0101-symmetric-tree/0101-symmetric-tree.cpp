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
bool check (TreeNode* a, TreeNode* b){
     if(a==NULL && b==NULL)return true;
     if(a==NULL || b==NULL)return false;
    bool x = check(a->left,b->right);
    bool y = check(a->right,b->left);
     if(a->val == b->val && x&&y)return true;
     return false;
}
    bool isSymmetric(TreeNode* root) {
        return check(root->left,root->right);
    }
};
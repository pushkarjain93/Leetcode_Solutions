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
int check (TreeNode* root,int &ans){
    if(root == NULL)return 0;
    int x = check(root->left,ans);
    int y = check(root->right,ans);
    ans=max(ans,x+y+root->val);
    return max(0,root->val + max(x,y));
}
    int maxPathSum(TreeNode* root) {
        int ans = INT_MIN;
        check(root,ans);return ans;
    }
};
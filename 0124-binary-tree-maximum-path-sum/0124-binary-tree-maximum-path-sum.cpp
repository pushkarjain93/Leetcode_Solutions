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
    int x = max(0,check(root->left,ans));
    int y = max(0,check(root->right,ans));
    // if on leftt i am getting a neg sum i will take it as 0
    // if on right i am getting a neg sum i will take it as 0
    ans=max(ans,x+y+root->val);
    return root->val + max(x,y);
}
    int maxPathSum(TreeNode* root) {
        int ans = INT_MIN;
        check(root,ans);return ans;
    }
};
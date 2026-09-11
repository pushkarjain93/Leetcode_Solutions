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
int rec1(TreeNode* root,int &ans){
   if(root==NULL)return INT_MAX;
  int x = rec1(root->left,ans);
  int y = rec1(root->right,ans);
  int mn = min({x,y,root->val});
  ans = max(ans,root->val-mn);
  return mn;
}
int rec2(TreeNode* root,int &ans){
   if(root==NULL)return 0;
  int x = rec2(root->left,ans);
  int y = rec2(root->right,ans);
  int mn = max({x,y,root->val});
  ans = max(ans,mn-root->val);
  return mn;
}

    int maxAncestorDiff(TreeNode* root) {
        int ans1 = 0;int ans2 = ans1;
        int x = rec1(root,ans1);
        int y = rec2(root,ans2);
        return max(ans1,ans2);
    }
};
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
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
      if(root==NULL)return{};
        queue<TreeNode*>q;
          q.push(root);
          vector<vector<int>>ans;int x=0;
        while(q.size()>0){
           int n = q.size();
           vector<int>temp(n);x++;
           for(int i=0;i<n;i++){
              TreeNode* t = q.front();q.pop();
              if(x%2==0) temp[n-i-1]=t->val;
             else temp[i]=(t->val);
              if(t->left != NULL){q.push(t->left);}
              if(t->right != NULL){q.push(t->right);}
           }
           ans.push_back(temp);
        }
        return ans;
    }
};
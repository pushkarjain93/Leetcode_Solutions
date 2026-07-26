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
    vector<vector<int>> levelOrder(TreeNode* root) {
        if(root == NULL)return {};
        queue<TreeNode*>q;
        q.push(root);
        vector<vector<int>>ans;
        while(!(q.empty())){
            vector<int>temp;
            int n = q.size();
            for(int i = 0 ; i < n ; i++){
                TreeNode* tp = q.front();
                  temp.push_back(tp->val);
                  if(tp->left != NULL)q.push(tp->left);
                  if(tp->right != NULL)q.push(tp->right);
                  q.pop();
            }
            ans.push_back(temp);
        }
        return ans;
    }
};
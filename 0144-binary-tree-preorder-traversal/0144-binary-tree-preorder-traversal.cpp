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
    vector<int> preorderTraversal(TreeNode* root) {
        if(root==NULL)return {};
        stack<TreeNode*>st;
        vector<int>ans;
        st.push(root);
        while(st.size()>0){
                TreeNode* tp = st.top();st.pop();
                ans.push_back(tp->val);
                if(tp->right)st.push(tp->right);
                if(tp->left)st.push(tp->left);
        }return ans;
    }
};
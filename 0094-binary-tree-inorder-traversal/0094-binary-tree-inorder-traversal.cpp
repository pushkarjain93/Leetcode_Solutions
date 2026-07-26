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
    vector<int> inorderTraversal(TreeNode* root) {
        if(root == NULL)return {};
        vector<int>ans;
        stack<TreeNode*>st;
        TreeNode* t= root;
        while(1){
            if(t!=NULL){
                st.push(t);t=t->left;
            }
            else{
                if(st.size()==0)break;
               TreeNode* tp =st.top();
               st.pop();
               ans.push_back(tp->val);
               t=tp->right;
            }
        }
        return ans;
    }
};
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
    int widthOfBinaryTree(TreeNode* root) {
       queue<pair<TreeNode*,long long>>q;
       q.push({root,0});
       long long int ans=1;
       while(q.size()>0){
         int n = q.size();
         long long int mn =LLONG_MAX;
         long long int mx = 0;
         long long int y = q.front().second;
         for(int i=0;i<n;i++){
            TreeNode* t = q.front().first;
           long long int x = q.front().second-y;mn=min(mn,x);mx=max(mx,x);
            ans=max(ans,mx-mn+1);
            q.pop();
            if(t->left == NULL && t->right ==NULL)continue;
                if(t->left !=NULL){q.push({t->left,2*1ll*x});}
                if(t->right){q.push({t->right,(2*1ll*x)+1});}
         }
       }return ans;
    }
};
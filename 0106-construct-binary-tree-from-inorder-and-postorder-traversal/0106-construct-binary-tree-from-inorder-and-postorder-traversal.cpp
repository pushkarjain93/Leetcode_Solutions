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
TreeNode* p(vector<int>&postorder,vector<int>&inorder,int ins,int ine,int posts,int poste,unordered_map<int,int>&f){
    // 3 20 7 15 9 is postorder (root right left)
    // 9 3 15 20 7 is inorder (left root right)
    if(ine<ins || poste<posts)return NULL;
    int x = postorder[posts];
    // for leftsubtree
    int newinsl = ins;
    int newinel = f[x]-1;
    int newpostsl =posts+(ine-f[x])+1;
    int newpostel =posts+ine-ins; 
    TreeNode* currleft = p(postorder,inorder,newinsl,newinel,newpostsl,newpostel,f);
    // for rightsubtree
     int newinsr = f[x]+1;
     int newiner = ine;
     int newpostsr =  posts+1;
     int newposter = posts+(ine-f[x]);
     TreeNode* currright = p(postorder,inorder,newinsr,newiner,newpostsr,newposter,f);
      TreeNode* currroot = new TreeNode(x,currleft,currright);
      return currroot;
 }
    TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
        int n = inorder.size();
        unordered_map<int,int>f;
        for(int i=0;i<n;i++)f[inorder[i]]=i;
        reverse(postorder.begin(),postorder.end());
      return p(postorder,inorder,0,n-1,0,n-1,f);
    }
};
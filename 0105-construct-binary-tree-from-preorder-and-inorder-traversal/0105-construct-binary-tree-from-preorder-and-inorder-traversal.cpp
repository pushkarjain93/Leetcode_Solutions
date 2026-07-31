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
 TreeNode* p(vector<int>&preorder,vector<int>&inorder,int ins,int ine,int pres,int pree,unordered_map<int,int>&f,int n){
    if(ine<ins || pree<pres)return NULL;
    int x = preorder[pres];
    // for leftsubtree
    int newinsl = ins;
    int newinel = f[x]-1;
    int newpresl = pres+1;
    int newpreel = pres+(f[x]-ins);
    TreeNode* currleft = p(preorder,inorder,newinsl,newinel,newpresl,newpreel,f,n);
    // for rightsubtree
     int newinsr = f[x]+1;
     int newiner = ine;
     int newpresr = pres+(f[x]-ins)+1;
     int newpreer = pres+ine-ins;
     TreeNode* currright = p(preorder,inorder,newinsr,newiner,newpresr,newpreer,f,n);
      TreeNode* currroot = new TreeNode(x,currleft,currright);
      return currroot;
 }
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        unordered_map<int,int>f;
        int n = inorder.size();
        for(int i=0;i<n;i++)f[inorder[i]]=i;
        return p(preorder,inorder,0,n-1,0,n-1,f,n);
    }
};
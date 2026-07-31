/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Codec {
public:
    // Encodes a tree to a single string.
    string serialize(TreeNode* root) {
        if (root == NULL)return "";
        string s = "";
        queue<TreeNode*> q;
        q.push(root);
        while (q.size() > 0) {
                TreeNode* curr = q.front();
                q.pop();
                if (curr == NULL) {
                    s += "#,";
                }
                else{
                string temp = to_string(curr->val);
                s += temp + ",";
                q.push(curr->left);
                q.push(curr->right);}
            }
        return s;
    }
    // Decodes your encoded data to tree.
    TreeNode* deserialize(string s) {
        if (s.size() == 0)return NULL;
        int i = 0;
        string temp = "";
        while(s[i]!=','){
            temp+=s[i];i++;
        }i++;
        queue<TreeNode*>q;
        TreeNode* root = new TreeNode(stoi(temp));
        q.push(root);temp="";
        while(q.size()>0 && i<s.size()){
           TreeNode* curr = q.front();
               q.pop();
           if(i<s.size()&&s[i]=='#'){
            i+=2;
            }
            else if(i<s.size() && s[i]!='#')
            {
             temp = "";
            while(i<s.size() && s[i]!=','){
            temp+=s[i];i++;
           }i++;
           curr->left = new TreeNode(stoi(temp));
            q.push(curr->left);
            }
            if(i<s.size() && s[i]=='#'){
            i+=2;
            }
            else if(i<s.size() && s[i]!='#')
            {
                temp="";
           while(i<s.size() && s[i]!=','){
            temp+=s[i];i++;
           }i++;
           curr->right = new TreeNode(stoi(temp));
           q.push(curr->right);
         }
        }
        return root;
    }
};

// Your Codec object will be instantiated and called as such:
// Codec ser, deser;
// TreeNode* ans = deser.deserialize(ser.serialize(root));
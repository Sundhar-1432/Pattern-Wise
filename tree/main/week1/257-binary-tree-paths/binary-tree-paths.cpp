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
    void path_traverse(TreeNode* root,string res,vector<string>&ans){
        if(!root)return;
        if(res!="")res+="->";
        res+=to_string(root->val);
        
        if(!root->left&&!root->right){

            ans.push_back(res);
            return;
        }
        
        path_traverse(root->left,res,ans);
        path_traverse(root->right,res,ans);        
    }
    vector<string> binaryTreePaths(TreeNode* root) {
        vector<string>ans;
        path_traverse(root,"",ans);
        return ans;
    }
};
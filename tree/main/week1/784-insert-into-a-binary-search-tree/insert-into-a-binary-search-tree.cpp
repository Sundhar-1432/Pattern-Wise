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
    TreeNode* insert(TreeNode* root, int val) {
        if(!root)return nullptr;
       if(root->val>val){
            TreeNode* left=insert(root->left,val);
            if(!left)root->left=new TreeNode(val);
       } else {
            TreeNode* right=insert(root->right,val);
            if(!right)root->right=new TreeNode(val);
       }

       return root;
    }
    TreeNode* insertIntoBST(TreeNode* root, int val) {
        TreeNode* temp=insert(root,val);
        if(!temp){
            return new TreeNode(val);
        }
        return temp;
    }
};
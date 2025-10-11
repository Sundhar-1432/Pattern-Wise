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
    int min_path(TreeNode* root){
        if(root&&!root->left&&!root->right)return 1;
        if(!root)return INT_MAX;
        //if(!root->left||!root->right)
        int left=min_path(root->left);
        int right=min_path(root->right);

        return 1+min(left,right);
    }
    int minDepth(TreeNode* root) {
        int n=min_path(root);
        return n==INT_MAX?0:n;
    }
};
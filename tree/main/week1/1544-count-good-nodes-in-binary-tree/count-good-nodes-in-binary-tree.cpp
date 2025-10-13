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
    void counting(TreeNode* root,int max_value,int &ans){
        if(!root)return ;
        if(root->val>=max_value){
            ans++;
            max_value=root->val;
        }
        counting(root->left,max_value,ans);
        counting(root->right,max_value,ans);
    }
    int goodNodes(TreeNode* root) {
        int ans=0;
        counting(root,INT_MIN,ans);
        return ans;
    }
};
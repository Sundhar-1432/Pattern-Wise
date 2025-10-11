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
    void pathSum(TreeNode* root, int targetSum,int sum,bool &ans) {
        if(!root)return;
        sum=root->val+sum;
        if(!root->right&&!root->left&&sum==targetSum)ans=true;
        pathSum(root->left,targetSum,sum,ans);
        pathSum(root->right,targetSum,sum,ans);
    }
    bool hasPathSum(TreeNode* root, int targetSum) {
        bool ans=false;
        pathSum(root,targetSum,0,ans);
        return ans==true?true:false;
    }
};
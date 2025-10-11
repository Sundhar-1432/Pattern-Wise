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
    vector<vector<int>>res;
    void path_sum(TreeNode*root,vector<int>path,int target){
        if(!root)return ;
        path.push_back(root->val);
        if(!root->left&&!root->right&&root->val==target){
            res.push_back(path);
        }else{
            path_sum(root->left,path,target-root->val);
            path_sum(root->right,path,target-root->val);
        }

        path.pop_back();
    }

    vector<vector<int>> pathSum(TreeNode* root, int targetSum) {
        vector<int>arr;
        path_sum(root,arr,targetSum);

        return res;
    }
};
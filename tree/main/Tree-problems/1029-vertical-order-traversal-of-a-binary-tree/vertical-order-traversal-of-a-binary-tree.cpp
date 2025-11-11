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
    map<int,vector<pair<int,int>>>mp;
    void traverse(TreeNode* root,int row,int col){
        if(!root)return ;
        mp[col].push_back({row,root->val});
        traverse(root->left,row+1,col-1);
        traverse(root->right,row+1,col+1);
    }
    vector<vector<int>> verticalTraversal(TreeNode* root) {
        
        traverse(root,0,0);
        vector<vector<int>>ans;
        for(auto [ft,sec]:mp){
            sort(sec.begin(),sec.end());
            vector<int>temp;
           for(auto it:sec)temp.push_back(it.second);
           ans.push_back(temp);
           
        }
        return ans;
    }
};
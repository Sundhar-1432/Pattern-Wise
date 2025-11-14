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
    vector<int> rightSideView(TreeNode* root) {
        if(!root)return {};
        queue<TreeNode*>q;
        q.push(root);
        vector<int>ans;
        
        ans.push_back(root->val);
        while(!q.empty()){
            int n=q.size();
            bool check=false;
            for(int i=0;i<n;i++){
                TreeNode* temp=q.front();q.pop();
                if(temp->right){
                    q.push(temp->right);
                    if(!check){
                        ans.push_back(temp->right->val);
                        check=true;
                    }
                }
                if(temp->left){
                    q.push(temp->left);
                    if(!check){
                        ans.push_back(temp->left->val);
                        check=true;    
                    }
                }
                
            }
        }
        return ans;
    }
};
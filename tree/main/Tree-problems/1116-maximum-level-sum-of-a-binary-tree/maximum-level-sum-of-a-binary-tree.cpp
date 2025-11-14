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
    int maxLevelSum(TreeNode* root) {

        if(!root)return 0;
        queue<TreeNode*>q;
        q.push(root);

        int i=0,max_sum=INT_MIN,level=1;
        while(!q.empty()){
            i++;
            int n=q.size(),sum=0;
            for(int i=0;i<n;i++){
                TreeNode* node=q.front();q.pop();
                sum+=node->val;
                if(node->left)q.push(node->left);
                if(node->right)q.push(node->right);
            }
            if(sum>max_sum){
                max_sum=sum;
                level=i;
            }
            
        }
        
        return level;
    }
};
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
    long long kthLargestLevelSum(TreeNode* root, int k) {
        
        queue<TreeNode*>q;
        q.push(root);
        vector<long long>arr;
        while(!q.empty()){
            long long sum=0;
            int n=q.size();
            for(int i=0;i<n;i++){
                TreeNode* temp=q.front();q.pop();
                sum+=temp->val;
                if(temp->left)q.push(temp->left);
                if(temp->right)q.push(temp->right);
            }
            arr.push_back(sum);
        }
        if(k>arr.size())return -1;
        sort(arr.begin(),arr.end());

        return arr[arr.size()-k];
    }
};
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
    TreeNode* build(vector<int>&preorder,int &i,int low,int high){
       
        if(i>=preorder.size())return nullptr;

        int val=preorder[i];
        if(val<low||val>high)return nullptr;

        i++;

        TreeNode* root=new TreeNode(val);

        root->left=build(preorder,i,low,val-1);
        root->right=build(preorder,i,val+1,high);

        return root;
    }
    TreeNode* bstFromPreorder(vector<int>& preorder) {
        int i=0;
        return build(preorder,i,INT_MIN,INT_MAX);
    }
};
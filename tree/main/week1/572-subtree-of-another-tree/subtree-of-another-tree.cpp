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
    bool sameTree(TreeNode* q,TreeNode* p){
        if(!q&&!p)return true;
        if(!q||!p)return false;
        if(q->val!=p->val)return false;

        return sameTree(q->left,p->left)&&sameTree(q->right,p->right);
    }
    bool isSubtree(TreeNode* root, TreeNode* subRoot) {
        if(!root)return false;
        bool ans=sameTree(root,subRoot);

        cout<<ans<<"  ";
        if(ans==true)return true;
        bool left_ans=isSubtree(root->left,subRoot);
        bool right_ans=isSubtree(root->right,subRoot);
        if(left_ans||right_ans)return true;

        return false;
    }
};
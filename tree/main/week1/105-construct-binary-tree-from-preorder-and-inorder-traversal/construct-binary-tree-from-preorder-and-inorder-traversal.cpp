/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left),
 * right(right) {}
 * };
 */
class Solution {
public:
    unordered_map<int, int> mp;
    int preIndex = 0;
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        for (int i = 0; i < inorder.size(); i++) {
            mp[inorder[i]] = i;
        }

        return BT(preorder, inorder, 0, inorder.size() - 1);
    }
    TreeNode* BT(vector<int>& preorder, vector<int>& inorder,int left,int right){
    if (left > right)
        return nullptr;

    int val = preorder[preIndex];
    preIndex++;
    TreeNode* root = new TreeNode(val);
    int indx = mp[val];

    root->left = BT(preorder, inorder, left, indx - 1);
    root->right = BT(preorder, inorder, indx + 1, right);

    return root;
    }
};
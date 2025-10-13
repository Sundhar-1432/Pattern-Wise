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
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
        if (!root)
            return {};
        vector<vector<int>> res;
        int cnt = 0;
        queue<TreeNode*> q;
        q.push(root);
        while (!q.empty()) {
            vector<int> temp;
            int n = q.size();
            for (int i = 0; i < n; i++) {
                TreeNode* dup = q.front();
                q.pop();

                temp.push_back(dup->val);
                if (dup->left)
                    q.push(dup->left);
                if (dup->right)
                    q.push(dup->right);
            }
            if (cnt % 2 != 0) {
                reverse(temp.begin(), temp.end());
                res.push_back(temp);
            } else
                res.push_back(temp);
            cnt++;
        }
        return res;
    }
};
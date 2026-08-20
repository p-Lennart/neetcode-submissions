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
    bool isValidBST(TreeNode* root) {
        // bfs version
        queue<tuple<TreeNode *, int, int>> q;
        q.push({root, -1 * INT_MAX, INT_MAX});
        bool valid = true;

        while (!q.empty() && valid) {
            auto [ptr, left, right] = q.front();
            q.pop();

            if (!ptr) continue;
            int val = ptr->val;
            valid = (left < val && val < right);
            
            q.push({ ptr->left, left, val});
            q.push({ ptr->right, val, right});
        }

        return valid;
    }
};

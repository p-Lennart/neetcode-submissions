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
        queue<TreeNode *> q;
        vector<int> rightSkim;

        q.push(root);
        while (!q.empty()) {
            vector<TreeNode *> level;
            level.reserve(q.size());

            while (!q.empty()) {
                TreeNode *curr = q.front();
                q.pop();
                if (curr) level.push_back(curr);
            }

            if (!level.empty()) {
                for (TreeNode *parent : level) {
                    q.push(parent->left);
                    q.push(parent->right);
                }
                rightSkim.push_back(level.back()->val);
            }
        }

        return rightSkim;
    }
};

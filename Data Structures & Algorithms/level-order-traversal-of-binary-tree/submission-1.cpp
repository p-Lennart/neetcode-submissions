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
    vector<vector<int>> levelOrder(TreeNode* root) {
        // bfs version
        vector<vector<int>> result;
        
        int depth = 0;
        queue<TreeNode *> q;
        q.push(root);

        while (!q.empty()) {
            vector<TreeNode *> thisLevel;

            while (!q.empty()) {
                TreeNode *parent = q.front();
                q.pop();
                if (!parent) continue;
                thisLevel.push_back(parent);
            }

            if (thisLevel.empty()) continue;

            result.push_back(vector<int>());
            result[depth].reserve(thisLevel.size());

            for (TreeNode *parent : thisLevel) {
                q.push(parent->left);
                q.push(parent->right);
                result[depth].push_back(parent->val);
            }

            depth++;
        }

        return result;
    }
};

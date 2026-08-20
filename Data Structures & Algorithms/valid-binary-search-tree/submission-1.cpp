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
    struct Metadata {
        TreeNode *ptr;
        int l;
        int r;
    };
public:
    bool isValidBST(TreeNode* root) {
        // bfs version
        queue<Metadata> q;
        q.push({root, -1 * INT_MAX, INT_MAX});
        bool valid = true;

        while (!q.empty() && valid) {
            Metadata md = q.front();
            q.pop();

            if (!md.ptr) continue;
            int val = md.ptr->val;
            valid = (md.l < val && val < md.r);
            
            q.push({ md.ptr->left, md.l, val});
            q.push({ md.ptr->right, val, md.r});
        }

        return valid;
    }
};

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
    int goodNodes(TreeNode* root) {
        if (!root) return 0;
        return traceGoodNodes(root, root->val - 1);
    }
private:
    int traceGoodNodes(TreeNode *ptr, int traceMax) {
        if (!ptr) return 0;
        int counted = 0;
        if (ptr->val >= traceMax) {
            counted = 1;
            traceMax = ptr->val;
        }
        return counted
        + traceGoodNodes(ptr->left, traceMax) + traceGoodNodes(ptr->right, traceMax);
    }
};

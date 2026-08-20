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
        return traceValidBST(root, -1 * INT_MAX, INT_MAX);
    }
private:
    bool traceValidBST(TreeNode *ptr, int l, int r) {
        if (!ptr) return true;
        int val = ptr->val;
        bool valid = (val > l && val < r);
        return valid
        && traceValidBST(ptr->left, l, val) && traceValidBST(ptr->right, val, r); 
    }
};

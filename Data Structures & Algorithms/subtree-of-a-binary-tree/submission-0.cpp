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
    bool isSubtree(TreeNode* root, TreeNode* subRoot) {
        if (!root) return false;
        bool matched = false;
        if (root->val == subRoot->val) matched = matchSubtree(root, subRoot);
        return matched || isSubtree(root->left, subRoot) || isSubtree(root->right, subRoot);
    }
private:
    bool matchSubtree(TreeNode *ptrOg, TreeNode *ptrSub) {
        if (!ptrOg && !ptrSub) return true;
        if (!ptrOg || !ptrSub) return false;
        if (ptrOg->val != ptrSub->val) return false;
        return matchSubtree(ptrOg->left, ptrSub->left) && matchSubtree(ptrOg->right, ptrSub->right);
    }
};

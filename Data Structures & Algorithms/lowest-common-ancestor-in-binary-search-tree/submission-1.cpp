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
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        // inefficient brute force attempt
        if (!root) return NULL;
        
        pair<bool, bool> bothFound = {true, true};
        if (containsPQ(root->left, p, q) == bothFound) {
            return lowestCommonAncestor(root->left, p, q);
        }
        if (containsPQ(root->right, p, q) == bothFound) {
            return lowestCommonAncestor(root->right, p, q);
        }
        if (containsPQ(root, p, q) == bothFound) {
            return root;
        }
        return NULL;
    }
private:
    pair<bool, bool> containsPQ(TreeNode* root, TreeNode* p, TreeNode* q) {
        if (!root) return { false, false };
        pair<bool, bool> stateL = containsPQ(root->left, p, q);
        pair<bool, bool> stateR = containsPQ(root->right, p, q);

        return {
            stateL.first  || stateR.first  || root == p,
            stateL.second || stateR.second || root == q
        };
    }
};

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
        int valT = root->val;
        int valL = min(p->val, q->val);
        int valR = max(p->val, q->val);
        
        // Termination cases
        // overlap
        if (valL == valT || valT == valR) {
            return root;
        }
        // split 
        if (valL <= valT && valT <= valR) {
            return root;
        }        
        
        // Propagate, valT is on either side of both valL, valR
        if (valR < valT) {
            return lowestCommonAncestor(root->left, p, q);
        } else { // valT < (valL, valR)
            return lowestCommonAncestor(root->right, p, q);
        }
    }
};

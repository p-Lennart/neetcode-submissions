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
    int kthSmallest(TreeNode* root, int k) {
        if (!root) return 0;
        vector<int> flattened;
        inorder(root, flattened);
        if (flattened.size() < k) return 0;
        return flattened[k-1];
    }
private:
    void inorder(TreeNode *root, vector<int> &flat) {
        if (!root) return;
        inorder(root->left, flat);
        flat.push_back(root->val);
        inorder(root->right, flat);
    }
    // vector<int> inorder(TreeNode *root) {
    //     vector<int> flattened;
    //     if (!root) return flattened;
    //     stack<TreeNode *> q;
        
    //     q.push(root);
    //     while (!q.empty()) {
    //         TreeNode *tn = q.top();
    //         q.pop();
            
    //         if (!tn) continue;
    //         q.push(tn->left);
    //         flattened.push_back(tn->val);
    //         q.push(tn->right);
    //     }

    //     return flattened;
    // }
};

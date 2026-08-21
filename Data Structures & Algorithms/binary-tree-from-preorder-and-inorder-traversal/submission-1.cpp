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
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        vector<int> built;
        if (preorder.size() == 0) return nullptr;

        // find root: preorder is NLR
        int rootVal = preorder[0];
        auto rootIt = find(inorder.begin(), inorder.end(), rootVal);
        int rootIdx = rootIt - inorder.begin();

        vector<int> inorderL(inorder.begin(), rootIt);
        vector<int> inorderR(rootIt + 1, inorder.end());
        int sizeL = rootIdx;
        int sizeR = inorder.size() - (rootIdx + 1);

        TreeNode *rootN = new TreeNode(rootVal);
        
        vector<int> preorderL(preorder.begin() + 1, preorder.begin() + sizeL + 1);
        vector<int> preorderR(preorder.begin() + sizeL + 1, preorder.end());
        
        rootN->left = buildTree(preorderL, inorderL);
        rootN->right = buildTree(preorderR, inorderR);
        return rootN;        
    }
};

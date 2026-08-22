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
        TreeNode *result = buildSubtree(
            preorder.begin(), preorder.end(), inorder.begin(), inorder.end()
        );
        return result;
    }
private:
    TreeNode *buildSubtree(
        vector<int>::iterator preL,
        vector<int>::iterator preR,
        vector<int>::iterator inL,
        vector<int>::iterator inR
    ) {
        if (preL == preR) return nullptr;

        int rootVal = *preL;
        vector<int>::iterator inRoot = find(inL, inR, rootVal);

        int numLeft = inRoot - inL;
        vector<int>::iterator preLL = preL + 1; // start of new left section

        TreeNode *head = new TreeNode(rootVal);
        head->val = rootVal;
        head->left = buildSubtree(preLL, preLL + numLeft, inL, inRoot);
        head->right = buildSubtree(preLL + numLeft, preR, inRoot + 1, inR);

        return head;
    }
};

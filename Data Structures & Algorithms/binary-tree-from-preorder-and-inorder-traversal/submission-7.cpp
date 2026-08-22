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
        unordered_map<int, vector<int>::iterator> val_to_inIt;
        for (auto it = inorder.begin(); it != inorder.end(); it++) {
            val_to_inIt[*it] = it;
        }

        TreeNode *result = buildSubtree(
            preorder.begin(), preorder.end(), inorder.begin(), inorder.end(), val_to_inIt
        );
        return result;
    }
private:
    TreeNode *buildSubtree(
        vector<int>::iterator preL,
        vector<int>::iterator preR,
        vector<int>::iterator inL,
        vector<int>::iterator inR,
        unordered_map<int, vector<int>::iterator> &val_to_inIt
    ) {
        if (preL == preR) return nullptr;

        int rootVal = *preL;
        vector<int>::iterator inRoot = val_to_inIt[rootVal];

        int numLeft = inRoot - inL;
        vector<int>::iterator preLL = preL + 1; // start of new left section

        TreeNode *head = new TreeNode(rootVal);
        head->val = rootVal;
        head->left = buildSubtree(preLL, preLL + numLeft, inL, inRoot, val_to_inIt);
        head->right = buildSubtree(preLL + numLeft, preR, inRoot + 1, inR, val_to_inIt);

        return head;
    }
};

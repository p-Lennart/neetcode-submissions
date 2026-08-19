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
    vector<vector<int>> levelOrder(TreeNode* root) {
        vector<vector<int>> result;
        populateLevels(root, 0, result);
        return result;
    }
private:
    void populateLevels(TreeNode *ptr, int ptrLvl, vector<vector<int>> &levels) {
        if (!ptr) return;
        while (levels.size() < ptrLvl + 1) levels.push_back(vector<int>());
        levels[ptrLvl].push_back(ptr->val);

        populateLevels(ptr->left, ptrLvl + 1, levels);
        populateLevels(ptr->right, ptrLvl + 1, levels);
    }
};
